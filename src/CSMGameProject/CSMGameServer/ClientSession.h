#pragma once

#include "Config.h"
#include "PacketType.h"
#include "CircularBuffer.h"
#include <map>
#include <winsock2.h>
#include <my_global.h>
#include <mysql.h>

#pragma comment(lib, "libmySQL.lib")
#pragma comment(lib, "libmysql")

#pragma comment(lib, "mysqlclient")
#define BUFSIZE	(1024*10)

class ClientSession;
class ClientManager;
struct DatabaseJobContext;

struct OverlappedIO : public OVERLAPPED
{
	OverlappedIO() 
		: mObject(nullptr) {}
	ClientSession* mObject;
};

class ClientSession
{
public:
	ClientSession(SOCKET sock)
		: mConnected(false), mLogon(false), mSocket(sock), mPlayerId(-1), mSendBuffer(BUFSIZE), mRecvBuffer(BUFSIZE), mOverlappedSendRequested(0), mOverlappedRecvRequested(0)
		, mDbUpdateCount(0),GMYSQLConnection(NULL),GMYSQLCONN()
	{

		memset( &mClientAddr, 0, sizeof(SOCKADDR_IN) );
	}
	~ClientSession() {}


	void	OnRead( size_t len );
	void	OnWriteComplete( size_t len );

	bool	OnConnect( SOCKADDR_IN* addr );
	
	bool	PostRecv();

	bool	Send( );
	bool	Broadcast( PacketHeader* pkt );
	bool	BroadcastWithoutSelf( PacketHeader* pkt );
	bool	Write( PacketHeader* pkt);

	void	Disconnect();

	bool	IsConnected() const { return mConnected; }

	void	DatabaseJobDone( DatabaseJobContext* result );


	/// 현재 Send/Recv 요청 중인 상태인지 검사하기 위함
	void	IncOverlappedSendRequest()		{ ++mOverlappedSendRequested; }
	void	DecOverlappedSendRequest()		{ --mOverlappedSendRequested; }
	bool	DoingOverlappedSendOperation() const { return mOverlappedSendRequested > 0 ; }
	void	IncOverlappedRecvRequest()		{ ++mOverlappedRecvRequested; }
	void	DecOverlappedRecvRequest()		{ --mOverlappedRecvRequested; }
	bool	DoingOverlappedRecvOperation() const { return mOverlappedRecvRequested > 0 ; }
	
private:
	void	OnTick();

	void	LoginDone( int pid, double x, double y, double z, const char* name );
	void	UpdateDone();


public:
	std::map<short,void(*)(ClientSession* client, PacketHeader* header, CircularBuffer* buffer)> mPacketHandler;
	bool			mConnected;
	bool			mLogon;
	SOCKET			mSocket;
	
	MYSQL*			GMYSQLConnection;
	MYSQL			GMYSQLCONN;

	int				mPlayerId;
	int				mGameId;
	SOCKADDR_IN		mClientAddr;

	CircularBuffer	mSendBuffer;
	CircularBuffer	mRecvBuffer;

	OverlappedIO	mOverlappedSend;
	OverlappedIO	mOverlappedRecv;
	int				mOverlappedSendRequested;
	int				mOverlappedRecvRequested;

	int				mDbUpdateCount; ///< DB에 주기적으로 업데이트 하기 위한 변수

	friend class ClientManager;
};




void CALLBACK RecvCompletion( DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags );
void CALLBACK SendCompletion( DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags );

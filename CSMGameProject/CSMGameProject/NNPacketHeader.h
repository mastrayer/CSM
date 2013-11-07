
#pragma once

enum NNPacketTypes
{
	PKT_NONE	= 0,
	PKT_TEST	= 0xFF
};

#pragma pack(push, 1)

struct NNPacketHeader
{
	NNPacketHeader() : mSize(0), mType(PKT_NONE) {}
	short mSize;
	short mType;
};

struct TestPacket : public NNPacketHeader
{
	TestPacket()
	{
		mSize = sizeof(TestPacket) ;
		mType = PKT_TEST;
		m_Int = 10;
		m_Float = 10.f;
		m_Char = 2;
	}

	int m_Int;
	float m_Float;
	char m_Char;
};

#pragma pack(pop)
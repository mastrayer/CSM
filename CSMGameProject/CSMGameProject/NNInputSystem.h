
#pragma once

#include "NNConfig.h"
#include "NNPoint.h"

/* */
/* NNInputSystem
/* 키 입력을 담당하는 싱글톤 클래스
/* */

enum KeyState
{
	KEY_DOWN,
	KEY_PRESSED,
	KEY_UP,
	KEY_NOTPRESSED,
};

class NNInputSystem
{
private:
	static NNInputSystem* m_pInstance;

private:
	NNInputSystem();
	~NNInputSystem();

private:
	bool m_PrevKeyState[256];
	bool m_NowKeyState[256];
	int m_UpDirectKey;
	int m_DownDirectKey;
	int m_LeftDirectKey;
	int m_RightDirectKey;
	int m_AttackKey;
	int m_UserActiveSkillKey;
	int m_TypeActiveSkillKey;

		//VK_LBUTTON
public:
	static NNInputSystem* GetInstance();
	static void ReleaseInstance();

public:
	void UpdateKeyState();
	KeyState GetKeyState( int key );
	NNPoint GetMousePosition();

	void SetUpDirectKey( int key ) { m_UpDirectKey = key; }
	void SetDownDirectKey( int key ) { m_DownDirectKey = key; }
	void SetLeftDirectKey( int key ) { m_LeftDirectKey = key; }
	void SetRightDirectKey( int key ) { m_RightDirectKey = key; }
	void SetAttackKey( int key ) { m_AttackKey = key; }
	void SetUserActiveSkillKey( int key ) { m_UserActiveSkillKey = key; }
	void SetTypeActiveSkillKey( int key ) { m_TypeActiveSkillKey = key; }

	int GetUpDirectKeyState( ) { return GetKeyState(m_UpDirectKey); }
	int GetDownDirectKeyState( ) { return GetKeyState(m_DownDirectKey); }
	int GetLeftDirectKeyState( ) { return GetKeyState(m_LeftDirectKey); }
	int GetRightDirectKeyState( ) { return GetKeyState(m_RightDirectKey); }
	int GetAttackKeyState( ) { return GetKeyState(m_AttackKey); }
	int GetUserActiveSkillKeyState( ) { return GetKeyState(m_UserActiveSkillKey); }
	int GetTypeActiveSkillKeyState( ) { return GetKeyState(m_TypeActiveSkillKey); }
};



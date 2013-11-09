
#pragma once

enum NNPacketTypes
{
	PKT_NONE	= 0,
	PKT_TEST	= 0xFF
};

#pragma pack(push, 1)

struct NNPacketHeader
{
	NNPacketHeader() : m_Size(0), m_Type(PKT_NONE) {}
	short m_Size;
	short m_Type;
};

struct TestPacket : public NNPacketHeader
{
	TestPacket()
	{
		m_Size = sizeof(TestPacket) ;
		m_Type = PKT_TEST;
		m_Int = 10;
		m_Float = 10.f;
		m_Char = 2;
	}

	int m_Int;
	float m_Float;
	char m_Char;
};

#pragma pack(pop)
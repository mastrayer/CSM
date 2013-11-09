
#pragma once

enum PacketTypes
{
	PKT_TEST = 0,
};

#pragma pack(push,1)

struct NNPacketHeader
{
	NNPacketHeader() : m_Size(0), m_Type(0) {}
	short m_Size;
	short m_Type;
};

struct TestPacket : public NNPacketHeader
{
	TestPacket()
	{
		m_Size = sizeof(TestPacket) ;
		m_Type = PKT_TEST;
		m_Int = 0;
		m_Float = 0.f;
		m_Char = 0;
	}

	int m_Int;
	float m_Float;
	char m_Char;
};

#pragma pack(pop)
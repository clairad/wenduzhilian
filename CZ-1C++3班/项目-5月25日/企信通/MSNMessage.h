#pragma once
//#define CLIENT

enum {
	COMMEN_SEND_MSG = 0,
	COMMEN_RECV_MSG,
	FILE_SEND_MSG,
	FILE_RECV_MSG
};

struct MSNMessage
{
	int m_sendID;
	int m_recvID;
	char m_msgName[32];
	short m_msgSize;
	char tmp; //Ô¤Áô
	char m_msgMode;
	union
	{
		struct FileMsg{
			int m_fileID;
			int m_breakpoint;
			char m_msgCnt[972];
		}m_fileMsg;

		char m_msgCnt[980];
	}m_msgPack;
};

int MSNSendMsg();
int MSNRecvMsg();
int MSNSendMsgMulti();
int MSNSendFile();
int MSNRecvFile();

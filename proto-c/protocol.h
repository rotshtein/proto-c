#pragma once
#pragma pack (1)

typedef enum
{
	etErrorCodeSuccess = 0,
	etErrorCodeUsartNoData,
	etErrorCodeHwError,
	etErrorCodeDefineAnyError,
	etErrorCodeCrcError,
	etErrorCodeWrongSize,
	etErrorCodeNoMemory
}ErrorCode;


typedef _declspec(align(1)) struct  _msg
{
	unsigned char Preamble;
	unsigned short Length;
	unsigned char Opcode;
	unsigned char pData[1];
} Msg;

#define PROTOCOL_HEADER_SIZE		sizeof(Msg)-1
#define PROTOCOL_OVERHEAD_SIZE		PROTOCOL_HEADER_SIZE + 1
#define MAX_DATA_SIZE				128-PROTOCOL_OVERHEAD_SIZE
#define PROTOCOL_MESSAGE_PREAMBLE	0xFD
#define PROTOCOL_USE_MALLOC			FALSE


ErrorCode ProtocolBuildMessage(unsigned char *Dest, unsigned char opcode, unsigned char* data, unsigned short len);
unsigned short GetProtocolData(unsigned char *pBuffer);
unsigned short GetProtocolDataLength(Msg *pBuffer);
int IsProtocolMessageValid(Msg *pBuffer);
Msg * GetLastProtocolMessage();

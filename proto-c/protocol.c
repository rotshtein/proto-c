

#include "protocol.h"
#include "memory.h"
#if PROTOCOL_USE_MALLOC == TRUE
#include <malloc.h>
#else
unsigned char static_buffer[MAX_DATA_SIZE + PROTOCOL_OVERHEAD_SIZE];
#endif

Msg* lastMessage = 0;
unsigned char CalcCrc(unsigned char* buff, unsigned short len);

ErrorCode ProtocolBuildMessage(unsigned char *Dest, unsigned char opcode, unsigned char* data, unsigned short len)
{
	Msg *dest = (Msg *)Dest;

	if (Dest == 0)
	{
#if PROTOCOL_USE_MALLOC == TRUE
		dest = malloc(len + PROTOCOL_OVERHEAD_SIZE);
		if (dest == 0)
		{
			lastMessage = 0;
			return etErrorCodeNoMemory;
		}
#else
		if (len > MAX_DATA_SIZE)
		{
			lastMessage = etErrorCodeWrongSize;
			return 0;
		}
		dest = static_buffer;
#endif
	}
	//unsigned char *pData = ((char *)dest) + sizeof(Msg);
	lastMessage = dest;
	
	memcpy(dest->pData, data, len);
	
	dest->Length = len + PROTOCOL_OVERHEAD_SIZE;

	dest->Preamble = PROTOCOL_MESSAGE_PREAMBLE;
	dest->Opcode = opcode;

	dest->pData[len] = CalcCrc((unsigned char *)dest, dest->Length-1);

	return etErrorCodeSuccess;
}

unsigned char CalcCrc(unsigned char* buff, unsigned short len)
{
	unsigned int Sum = 0;

	while (len--)
	{
		Sum += *buff++;
	};

	return ~((unsigned char)(Sum % 256));
}

unsigned short GetProtocolDataLength(Msg *pBuffer)
{
	return (unsigned short)(pBuffer->Length - PROTOCOL_OVERHEAD_SIZE);
}

int IsProtocolMessageValid(Msg *pBuffer)
{
	if (pBuffer->Preamble != PROTOCOL_MESSAGE_PREAMBLE)
	{
		return 0;
	}

	int i = (CalcCrc((unsigned char *)pBuffer, pBuffer->Length - 1) == ((unsigned char *)pBuffer)[pBuffer->Length-1]);
	return i;
}

Msg *GetLastProtocolMessage()
{
	return lastMessage;
}


// proto-c.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "alerts.pb.h"
#include "protocol.h"
#include <malloc.h>

bool SetWarrning(Warnings *warn, int WorningNumber);

int main()
{
	uint8_t buffer[128];
	size_t message_length;
	bool status;
	
	/* Create a stream that will write to our buffer. */
	pb_ostream_t ostream = pb_ostream_from_buffer(buffer, sizeof(buffer));


	//=================== Decode =====================================
	Warnings warn = Warnings_init_zero;
	SetWarrning(&warn, 9);
	SetWarrning(&warn, 1);
	status = pb_encode(&ostream, Warnings_fields, &warn);
	message_length = ostream.bytes_written;
	/* Then just check for any errors.. */
	if (!status)
	{
		printf("Encoding failed: %s\n", PB_GET_ERROR(&ostream));
		return 1;
	}

	/********************************* BUILD PROTOCOL MESSAGE **************************/
	unsigned char *p = (unsigned char *)malloc(message_length + PROTOCOL_OVERHEAD_SIZE);
	ProtocolBuildMessage(p, (unsigned char)OPCODE_WARNINGS, buffer, (unsigned short)message_length);
	Msg* pMsg = GetLastProtocolMessage();

	/********************************* Send *******************************/
	/*********************************  |  ********************************/
	/*********************************  |  ********************************/
	/*********************************  |  ********************************/
	/*********************************  V  ********************************/
	/******************************* Receive ******************************/

	if (IsProtocolMessageValid(pMsg) != 0)
	{

		/* Create a stream that reads from the buffer. */
		pb_istream_t istream = pb_istream_from_buffer(pMsg->pData, message_length);
		switch (pMsg->Opcode)
		{
		case OPCODE_ACK:
		case OPCODE_NACK:
			break;

		case OPCODE_POLYGON_SETTING:
			break;

		case OPCODE_WARNINGS:
			Warnings decodeWarn = Warnings_init_zero;
			status = pb_decode(&istream, Warnings_fields, &decodeWarn);
			if (!status)
			{
				printf("Decoding failed: %s\n", PB_GET_ERROR(&istream));
				return 1;
			}

			/* Print the data contained in the message. */
			printf("Your warnings was %04X\n", (int)decodeWarn.warnings);

			break;

		default:
			break;
		}
		
	}
    return 0;
}

bool SetWarrning(Warnings *worn , int WarningNumber)
{
	if (WarningNumber > (sizeof(worn->warnings) * 8))
	{
		return false;
	}

	worn->warnings |= (unsigned short)(1 << (WarningNumber-1));
	return true;
}



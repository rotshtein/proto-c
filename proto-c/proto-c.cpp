// proto-c.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "alerts.pb.h"

bool SetWorrning(Warnings *worn, int WorningNumber);

int main()
{
	uint8_t buffer[128];
	size_t message_length;
	bool status;
	
	/* Create a stream that will write to our buffer. */
	pb_ostream_t ostream = pb_ostream_from_buffer(buffer, sizeof(buffer));

	//=================== Decode =====================================
	Warnings warn = Warnings_init_zero;
	SetWorrning(&warn, 9);
	SetWorrning(&warn, 1);
	status = pb_encode(&ostream, Warnings_fields, &warn);
	message_length = ostream.bytes_written;

	/* Then just check for any errors.. */
	if (!status)
	{
		printf("Encoding failed: %s\n", PB_GET_ERROR(&ostream));
		return 1;
	}

	Warnings decodeWarn = Warnings_init_zero;

	/* Create a stream that reads from the buffer. */
	pb_istream_t istream = pb_istream_from_buffer(buffer, message_length);
	status = pb_decode(&istream, Warnings_fields, &decodeWarn);
	if (!status)
	{
		printf("Decoding failed: %s\n", PB_GET_ERROR(&istream));
		return 1;
	}

	/* Print the data contained in the message. */
	printf("Your warnings was %04X\n", (int)decodeWarn.wornings);
    return 0;
}

bool SetWorrning(Warnings *worn , int WorningNumber)
{
	if (WorningNumber > (sizeof(worn->wornings) * 8))
	{
		return false;
	}

	worn->wornings |= (unsigned short)(1 << (WorningNumber-1));
	return true;
}



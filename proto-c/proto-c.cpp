// proto-c.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "alerts.pb.h"

int main()
{
	uint8_t buffer[128];
	size_t message_length;
	bool status;
	
	/* Create a stream that will write to our buffer. */
	pb_ostream_t ostream = pb_ostream_from_buffer(buffer, sizeof(buffer));

	//=================== Decode =====================================
	char warnings[2] = { 0, 1 };
	Warnings warn = Warnings_init_zero;
	warn.wornings.size = 2;
	memcpy(warn.wornings.bytes, warnings, warn.wornings.size);
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
	printf("Your warnings was %d,%d\n", (int)decodeWarn.wornings.bytes[1], (int)decodeWarn.wornings.bytes[0]);
    return 0;
}



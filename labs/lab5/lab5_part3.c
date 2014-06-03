#include <stdio.h>
#include <endian.h>
#include <stdint.h>

short swap_bytes(short val) {
	return (val >> 8) | ((val & 0xff) << 8);
}

int big_endian() {

	union {
		uint32_t i;
		char c[4];
	} e = {0x01000000};
	// return the 01 from e if the system is big endian
	return e.c[0];
}

int main(int argc, char **argv)
{
	short val;
	char *p_val;
	p_val = (char *) &val;
	/*
		The following two lines assume big-endian
		Architecture to initialize the variable Val
		to 0x1234.
	*/
	p_val[0] = 0x12;
	p_val[1] = 0x34;
	
	if (!(big_endian())) {
		val = swap_bytes(val);
	}
	
	printf("%x\n", val);
	
	return 0;
}
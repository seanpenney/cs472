#include <stdio.h>
#include <endian.h>

short swap_bytes(short val) {
	return (val >> 8) | ((val & 0xff) << 8);
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
	
	if (!(__BIG_ENDIAN)) {
		val = swap_bytes(val);
	}
	
	printf("%x\n", val);
	
	return 0;
}
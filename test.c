
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int a = 97;
	char b = (char)a;
	printf("%c\n", b);
}

char[64] original_binary
char[8] result
counter = 0;
for (i = 0; i < 8; i++) {
	currentVal = 0;
	for (j = 0; j < 8; j++) {
		// add on value of binary digit
		// each character starts at most significant digit,
		// goes down to LSB, hence why it is 2^(7-j)
		currentVal += original_binary[counter] * 2^(7-j)
		counter++;
	}
	result[i] = (char)currentVal
}
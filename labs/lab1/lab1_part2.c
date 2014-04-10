#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char* x = argv[1];

	int double_sign = x[0];
	printf("The sign is %c (where 0 is positive and 1 is negative) if the value is treated as a double\n", double_sign);

	int mantis = mantissa_calc(x);
	printf("The mantissa is %d if the value is treated as a double\n", mantis);

	int expo = exponent_calc(x);
	printf("The exponent is %d if the value is treated as a double\n", expo);

	int long_val = long_value_calc(x);
	int long_sign = x[0];
	int char1 = read_char(x, 0);
	int char2 = read_char(x, 8);
	int char3 = read_char(x, 16);
	int char4 = read_char(x, 24);
	int char5 = read_char(x, 32);
	int char6 = read_char(x, 40);
	int char7 = read_char(x, 48);
	int char8 = read_char(x, 56);


	printf("The value is %d if the value is treated as a long\n", long_val);
	printf("The sign is %c (where 0 is positive and 1 is negative) if the value is treated as a long\n", long_sign); 
	printf("The characters are %c, %c, %c, %c, %c, %c, %c, %c \n", char1, char2, char3, char4, char5, char6, char7, char8);


	exit(EXIT_SUCCESS);
}

int exponent_calc(char* x) {
	int binary_val = 1;
	int total_val = 0;
	
	//calculate binary value of the exponent
	for(int i = 11; i > 0; i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

int mantissa_calc(char* x) {
	int binary_val = 1;
	int total_val = 0;

	for(int i = 63; i > 11; i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

int long_value_calc(char* x) {
	int binary_val = 1;
	int total_val = 0;

	for(int i = 63; i > 0; i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

int read_char(char* x, int start) {
	int binary_val = 1;
	int total_val = 0;

	for(int i = (start + 7); i >= (start); i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

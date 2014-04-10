// Sean Penney and Paul Atkinson
// Part 2 of lab1, feature extraction

#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int exponent_calc(char* x);
double mantissa_calc(char* x);
double long_value_calc(char* x);
int read_char(char* x, int start);

int main(int argc, char *argv[])
{
	char* x = argv[1]; // bit pattern passed as command line argument

	// following the IEEE 754 format, the first bit in a double represents the sign
	int double_sign = x[0];
	printf("The sign is %c (where 0 is positive and 1 is negative) if the value is treated as a double\n", double_sign);
	
	double mantis = mantissa_calc(x); // calculate mantissa of a double
	printf("The mantissa is %f if the value is treated as a double\n", mantis);

	int expo = exponent_calc(x); // calculate exponent of a double
	printf("The exponent is %d if the value is treated as a double\n", expo);

	double long_val = long_value_calc(x); // calculate value of a long
	int long_sign = x[0]; // sign of a long is the first bit
	
	// calculate the characters of the bit pattern
	int char1 = read_char(x, 0);
	int char2 = read_char(x, 8);
	int char3 = read_char(x, 16);
	int char4 = read_char(x, 24);
	int char5 = read_char(x, 32);
	int char6 = read_char(x, 40);
	int char7 = read_char(x, 48);
	int char8 = read_char(x, 56);

	printf("The value is %f if the value is treated as a long\n", long_val);
	printf("The sign is %c (where 0 is positive and 1 is negative) if the value is treated as a long\n", long_sign); 
	printf("The characters are %c, %c, %c, %c, %c, %c, %c, %c \n", char1, char2, char3, char4, char5, char6, char7, char8);


	exit(EXIT_SUCCESS);
}
// calculate exponent if value is treated as double
int exponent_calc(char* x) {
	int binary_val = 1;
	int total_val = 0;
	
	//calculate binary value of the exponent
	for(int i = 11; i > 0; i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}
		// multiply by 2 since the next iteration is for the next greatest binary digit
		binary_val = binary_val * 2;
	}
	return total_val;
}

// calculate mantissa if value is treated as double
double mantissa_calc(char* x) {
	double binary_val = 1;
	double total_val = 0;

	for(int i = 63; i > 11; i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}
		// multiply by 2 since the next iteration is for the next greatest binary digit
		binary_val = binary_val * 2;
	}
	return total_val;
}

// calculate value if binary pattern treated as long
double long_value_calc(char* x) {
	double binary_val = 1;
	double total_val = 0;

	// value follows the first bit (sign bit)
	for(int i = 63; i > 0; i--) {
		if(x[i] == '1') {
			total_val += binary_val;
		}
		// multiply by 2 since the next iteration is for the next greatest binary digit
		binary_val = binary_val * 2;
	}
	return total_val;
}

// convert binary digits representing ascii values into character
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

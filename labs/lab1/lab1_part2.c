#include <math.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char* x = argv[1];
	int double_sign = x[0];
	int expo = exponent_calc(x);
	int mantis = mantissa_calc(x);

	int long_val = long_value_calc(x);
	int long_sign = x[0];
	int char_1 = read_char(x, 1);

	printf("The sign is %d (where 1 is positive and 0 is negative) if the value is treated as a double\n", double_sign);
	printf("The mantissa is %d if the value is treated as a double\n", mantis);
	printf("The exponent is %d if the value is treated as a double\n", expo);

	printf("The value is %d if the value is treated as a long\n", long_val);
	printf("The sign is %d (where 1 is positive and 0 is negative) if the value is treated as a long\n", long_sign); 

	exit(EXIT_SUCCESS);
}

int exponent_calc(char* x) {
	int binary_val = 1;
	int total_val = 0;
	
	//calculate binary value of the exponent
	for(int i = 11; i > 0; i--) {
		if(x[i] == 1) {
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
		if(x[i] == 1) {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

int long_val(char* x) {
	int binary_val = 1;
	int total_val = 0;

	for(int i = 63; i > 0; i--) {
		if(x[i] == 1) {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

int read_char(char* x, int start) {
	int binary_val = 1;
	int total_val = 0;

	for(int i = (start + 7); i > (start - 1); i--) {
		if(x[i] == 1) {
			total_val += binary_val;
		}

		binary_val = binary_val * 2;
	}
	return total_val;
}

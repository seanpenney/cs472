#include <math.h> 
#include <float.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char* var_word = argv[1];
	int halfsize = (strlen(var_word)/2);
	int true = 1;

	//check if var_word is odd
	if((strlen(var_word)%2) == 1) {
		for(int i = 0; i < halfsize; i++) {
			if(var_word[i] != var_word[strlen(var_word)-i -1]) {
				true = 0;
			}
		}
	} else {
		true = 0;
	}
	if(true == 1) {
		printf("Yes, it is a Palindrome\n");
	} else {
		printf("No, it is not a Palindrome\n");
	}

}

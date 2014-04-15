#include <math.h> 
#include <float.h> 
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	char* word = argv[1];
	int halfsize = (sizeof(word)/2)
	int true = 1;	


	//check if word is odd
	if((sizeof(word)%2) == 1) {
		for(int i = 0; i < halfsize; i++) {
			if(word[i] != word[sizeof(word)-i]) {
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

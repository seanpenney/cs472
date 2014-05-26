#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

clock_t clock_timer(int size) {

	//create a buffer
	volatile char *buffer = malloc(size * sizeof(char)); 
	clock_t start_time = clock(); 

	for (int64_t i = 0; i < (1024*1024); i++) {
		++buffer[(i * 64) % size]; //write in increments of size 
	}

	clock_t end_time = clock() - start_time; 
	free(buffer);
	return end_time;
} 

int main() {
	
	for(int j = 2; j <= 1024; j = j*2) {
		printf("size:%d kb \ttime:%d\n", j, clock_timer(j*1024)); 
	}
}

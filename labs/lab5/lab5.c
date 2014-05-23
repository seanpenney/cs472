#include <stdout> 
#include <time.h> 
#include <cstdio> 
clock_t clock_timer(int size) {

	//create a buffer volatile char* buffer = new char[size]; 
	clock_t start_time = clock(); 

	for (int64_t i = 0; i < (1024*1024); i++) {
		++buffer[(i * 64) % size]; //write in increments of size 
	}

	clock_t end_time = clock() - start_time; 
	delete [] buffer; return 
	end_time;
} 

int main() {
	for(j = 1; j < 1024; j = j*j) {
		printf("%d \t%d\n", j, clock_timer(j)); 
	}
}

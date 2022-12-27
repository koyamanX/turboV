#include <stdlib.h>
#include <stdio.h>

#define SIM_EXIT ((volatile unsigned int *) 0x80001000)

int main(void) {
	int *p;

	printf("%s\n", "Hello,world!");

	for(int i = 0; i < 1024; i++)
		asm volatile("nop");
	
	p = malloc(sizeof(int));

	*p = 1;

	*SIM_EXIT = *p;

	exit(EXIT_FAILURE);
}

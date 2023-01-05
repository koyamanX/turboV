#include <stdlib.h>

int main(void) {
	int *p;
	
	p = malloc(sizeof(int));

	*p = 1;

	*((unsigned int *) 0x80001000) = *p;

	exit(EXIT_FAILURE);
}

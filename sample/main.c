int main(void) {
	*((volatile unsigned int *) 0x80001000) = 0x1;
	return 0;
}

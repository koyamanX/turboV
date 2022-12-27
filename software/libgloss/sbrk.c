#include "libgloss_turboV.h"
#include <stdint.h>

extern char _heap_start;
extern char _heap_end;

void *_sbrk(intptr_t increment) {
	static char *heap = &_heap_start;

	if(&_heap_start == &_heap_end) {
		return (void *) -1;
	}
	if((heap + increment) >= &_heap_end) {
		heap = &_heap_end;
		return (void *) -1;
	}
	heap += increment;
	return (void *)(heap - increment);
}

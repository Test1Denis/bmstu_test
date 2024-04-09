#ifndef _ring_buffer_
#define _ring_buffer_

#include <iostream>

#define ERROR_OK	0
#define ERROR_FULL	1
#define ERROR_EMPTY	2
#define ERROR_INIT	3


enum class Error {
	OK = 0,
	FULL = 1,
	EMPTY = 2,
};

struct RingBuffer {
	int* ar_ {nullptr};
	int size_ar_ {-1};
	int datalen_;
	int ptrBegin_;
	int ptrEnd_;
};

void ring_Init(RingBuffer* buf, int size_ar);
int ring_AddToEnd(RingBuffer* buf, int el);
int ring_GetFromFront(RingBuffer* buf, int* el);

#endif

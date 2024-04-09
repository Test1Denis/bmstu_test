#include "ring_buffer.h"


void ring_Init(RingBuffer* buf, int size_ar) {
	buf->ar_ = new int [size_ar];
	buf->size_ar_ = size_ar;
	buf->datalen_ = 0;
	buf->ptrEnd_ = 6;
	buf->ptrBegin_ = buf->ptrEnd_;
}

int ring_AddToEnd(RingBuffer* buf, int el) {
	if (buf->ar_ == nullptr) {
		return ERROR_INIT;
	}

	if (buf->datalen_ > buf->size_ar_ - 1) {
		return ERROR_FULL;
	}

	buf->ar_[buf->ptrEnd_] = el;
	buf->ptrEnd_++;
	buf->datalen_++;
	if (buf->ptrEnd_ > (buf->size_ar_ - 1)) {
		buf->ptrEnd_ = 0;
	}

	return ERROR_OK;
}

int ring_GetFromFront(RingBuffer* buf, int* el) {
	if (buf->ar_ == nullptr) {
		return ERROR_INIT;
	}

	if (buf->datalen_ == 0) {
		return ERROR_EMPTY;
	}
	*el = buf->ar_[buf->ptrBegin_];
	buf->ptrBegin_++;
	buf->datalen_--;

	if (buf->ptrBegin_ == buf->size_ar_) {
		buf->ptrBegin_ = 0;
	}

	return ERROR_OK;
}



#include "ring_buffer.h"

RingBuffer::RingBuffer() {
	ar_ = new int [16];
	size_ar_ = 16;
	datalen_ = 0;
	ptrEnd_ = 6;
	ptrBegin_ = ptrEnd_;
	std::cout << __func__ << std::endl;
}

RingBuffer::RingBuffer(int size_ar) : RingBuffer() {
	size_ar_ = size_ar;
	delete [] ar_;
	ar_ = new int [size_ar_];

	std::cout << __func__ << std::endl;
}	

RingBuffer::~RingBuffer() {
	delete [] ar_;
	std::cout << __func__ << std::endl;
}

Error RingBuffer::ring_AddToEnd(int el) {
	if (ar_ == nullptr) {
		return Error::EMPTY;
	}

	if (datalen_ > size_ar_ - 1) {
		return Error::FULL;
	}

	ar_[ptrEnd_] = el;
	ptrEnd_++;
	datalen_++;
	if (ptrEnd_ > (size_ar_ - 1)) {
		ptrEnd_ = 0;
	}

	return Error::OK;
}

Error RingBuffer::ring_GetFromFront(int* el) {
	if (datalen_ == 0) {
		return Error::EMPTY;
	}
	*el = ar_[ptrBegin_];
	ptrBegin_++;
	datalen_--;

	if (ptrBegin_ == size_ar_) {
		ptrBegin_ = 0;
	}

	return Error::OK;

}



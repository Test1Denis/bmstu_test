#ifndef _ring_buffer_
#define _ring_buffer_

#include <iostream>
#include <cstring>

#define ERROR_OK	0
#define ERROR_FULL	1
#define ERROR_EMPTY	2
#define ERROR_INIT	3


enum class Error {
	OK = 0,
	FULL = 1,
	EMPTY = 2,
};

class RingBuffer {
	private :
		int* ar_;
		int size_ar_;
		int datalen_;
		int ptrBegin_;
		int ptrEnd_;

	public :
		RingBuffer();
		RingBuffer(int size_ar);
		~RingBuffer();
	
		Error ring_AddToEnd(int el);
		Error ring_GetFromFront(int* el);

		int getDatalen() const {
			return datalen_;
		}
		void getSizeAr(int size) {
			if (size < size_ar_) {
				return;
			}
			int* ar_temp = new int [size_ar_];
			memcpy(ar_temp, ar_, size_ar_ * sizeof(int));
			delete [] ar_;
			ar_ = new int [size];
			memcpy(ar_, ar_temp, size_ar_ * sizeof(int));
			delete [] ar_temp;
			size_ar_ = size;
		}
};

#endif

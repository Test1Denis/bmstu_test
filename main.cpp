#include <iostream>
#include "ring_buffer.h"


struct RingBuffer test_buf;

int error_ok() {
	std::cout << __LINE__ << " : " << __func__ << std::endl;
	return ERROR_OK;
}
int error_empty() {
	std::cout << __LINE__ << " : " << __func__ << std::endl;
	return ERROR_EMPTY;
}
int error_full() {
	std::cout << __LINE__ << " : " << __func__ << std::endl;
	return ERROR_FULL;
}
int error_init() {
	std::cout << __LINE__ << " : " << __func__ << std::endl;
	return ERROR_INIT;
}

int (*process_error[4])() = {error_ok, error_empty, error_full, error_init};

void test_ring_buffer() {

	int i = 0;
	int k = 0;
	for (;; i++) {
		if (process_error[ring_AddToEnd(&test_buf, i+1)]() != ERROR_OK) {
			break;
		}
/*
		switch (ring_AddToEnd(&test_buf, i+1)) {
			case ERROR_EMPTY :
			break;
			case ERROR_FULL :
			break;
			case ERROR_OK :
			break;
			case ERROR_INIT :
				std::cout << "not init" << std::endl;
			break;
		}
*/
	}

	std::cout << "count element = " << i << std::endl;
	std::cout << "count element = " << test_buf.datalen_ << std::endl;

	int element;
	for (i = 0;; i++) {
		if (ring_GetFromFront(&test_buf, &element) == ERROR_OK) {
			std::cout << "element = " << element << std::endl;
			continue;
		}
		std::cout << "error_empty" << std::endl;
		break;
	}

}
int main() {

//	ring_Init(&test_buf, 16);
	test_ring_buffer();
	std::cout << "---" << std::endl;
	test_ring_buffer();

	return 0;	

}

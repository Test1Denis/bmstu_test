#include <iostream>
#include "ring_buffer.h"



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

std::ostream& operator<<(std::ostream& out, const Error cur_er) {
	out << " Error = ";
	switch(cur_er) {
		case Error::OK :
			out << "OK";
		break;
		case Error::EMPTY :
			out << "empty";
		break;
		case Error::FULL :
			out << "full";
		break;
	}
	out << std::endl;

	return out;
}
int main() {

	class RingBuffer test_buf1;
	
	RingBuffer *test_buf2 = new RingBuffer(4);

	for (int i = 0; i < 8; i++) {
		std::cout << i << " : " << test_buf2->ring_AddToEnd(10);
	}

	delete test_buf2;

	std::cout << __LINE__ << std::endl;
	return 0;	
}

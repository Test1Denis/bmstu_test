#include <iostream>
#include "ring_buffer.h"
#include "filo_1.h"
#include "linked_list.h"
#include <cstdlib>
#include <chrono>

//template<typename T>
template<class T>
class Filo1 {
	private :
		T *ar;
		size_t size;
		size_t datalen;
	public: 
		Filo1() {
			ar = new T [8];
			size = 8;
			datalen = 0;
		}
		~Filo1() {
			delete [] ar;
		}
		int push(T el) {
			if (datalen == size) {
				return -1;
			}	
			ar[datalen++] = el;
			return 0;
		}
		int pull(T* el) {
			if (datalen == 0) {
				return -1;
			}
			*el = ar[--datalen];
			return 0;
		}
};


void testLinkedList() {
	LinkedList myList;

	Data temp("temp 1");
	
	for (int i = 0; i < 10; i++) {
		temp.str_[5] = (char)(i + 0x30);
		myList.Push(temp);
		
	}

	std::cout << "swap" << std::endl;
	myList.ShowElements();
	std::cout << "----" << std::endl;
	myList.SwapElement(0,5);
	std::cout << "----" << std::endl;
	myList.ShowElements();

	return;

	std::cout << "show el from tail" << std::endl;
	myList.ShowElementFromTail_asOneLL();
	std::cout << "----" << std::endl;

	std::cout << "get element 0 " << std::endl;
	char tempData[128];
	myList.getDataNode(0, tempData);
	std::cout << tempData << "\n----" << std::endl;
	std::cout << "get element 19 " << std::endl;
	myList.getDataNode(19, tempData);
	std::cout << tempData << "\n----" << std::endl;

	std::cout << "check pull function" << std::endl;
	for (int i = 0; i < 15; i++) {
		std::cout << i << " : ";
		if (myList.Pull(&temp) == 0) {
			std::cout << temp.str_ << std::endl; 
			continue;
		}
		std::cout << " no element" << std::endl;
	}
}


int main(int argc, char** argv) {

	const auto t1 = std::chrono::high_resolution_clock::now();	
	testLinkedList();
	const auto t2 = std::chrono::high_resolution_clock::now();

	auto tim = t2 - t1;
    const std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
	std::cout << fp_ms.count() << std::endl;

//	std::cout << fp_ms << std::endl;
	const auto int_ms = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::cout << int_ms << std::endl;
	
	return 0;
	Filo1<char> tempFilo;
	Filo1<double> tempFilo1;

	class Filo xz_filo;
	xz_filo.test();
	xz_filo.test1();

	tempFilo.push(10);
	char temp1;	
	tempFilo.pull(&temp1);


	return 0;	
}

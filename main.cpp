#include <iostream>
#include "ring_buffer.h"
#include "filo_1.h"
#include "linked_list.h"

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
		myList.Push(temp);
	}

	myList.ShowElements();

	for (int i = 0; i < 15; i++) {
		std::cout << i << " : ";
		if (myList.Pull(&temp) == 0) {
			std::cout << temp.str_ << std::endl; 
			continue;
		}
		std::cout << " no element" << std::endl;

				
	}
}

int main() {
	testLinkedList();
	
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

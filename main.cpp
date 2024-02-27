#include <algorithm>
#include <iostream>
#include <stdlib.h>

void GetA_doitany(int a) {
	switch(a) {
		case 0 :
			std::cout << "hi " << std::hex << a;
		break;
		case 1 :
			std::cout << "hello " << std::hex << a;
		break;
		
		case 2 :
		case 3 :
		case 4 :
		case 5 :
			std::cout << "privet " << std::hex << a;
		break;

		default:
			std::cout << "hren " << std::hex << a;
		break;

	}

	std::cout << std::endl;
}

void BubbleSort(int* ar, int size) {
	std::cout << "ona rabotaet " << __func__ << std::endl;

}

int GetMaxInd(cosnt int* ar, int size) {
	int indMax = 0;
	
	for (int i = 1; i < size; i++) {
		indMax = (ar[i] < ar[indMax]) ? indMax : i;
	}

	return indMax;
}

void SelectionSort(int *ar, int size) {
	for (int i = 0; i < size; i++) {
		int ind = GetMaxInd(&ar[i], size - i) + i;
		std::swap(ar[ind], ar[i]);
	}
}


int main(int argc, char** argv) {
	int a = -1;
	if (argc > 1) {
//		itoa -- convert integer to string
//	atoi -- convert str to int
		a = atoi(argv[1]);
	}
	GetA_doitany(a);
		
    return 0;
}


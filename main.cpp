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

int GetMaxInd(const int* ar, int size) {
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

	int ar[17] = {17,1,2,9,0,-1,6,6,2,8,7,3,6,6,6,9000, 9};
	SelectionSort(&ar[0], 17);

	std::cout << std::dec;

	for (int i = 0; i < 17; std::cout << ar[i++] << " ");
	std::cout << std::endl;
		
    return 0;
}


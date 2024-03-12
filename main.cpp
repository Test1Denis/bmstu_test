#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
//#include <string.h>

#include "sorts.h"

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int) = [](int a, int b){return a < b;}) {
	int i = 0;
	int j = 0;

	while (j < size) {
		i = 0;
		while (i < size - 1) {
			if (comp(ar[i], ar[i+1])) {
				std::swap(ar[i], ar[i+1]);
			}
			i++;
		}
		j++;
	}
}

void BubbleSortStandard(int* ar, size_t size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1; j++) {
			if (ar[i] > ar[i+1]) {
				std::swap(ar[i], ar[i+1]);
			}
		}
	}
}

bool CheckSort(const int* ar, size_t size) {
	for (int i = 0; i < size - 1; i++) {
		if (ar[i] < ar[i+1]) {
			return false;
		}
	}
	return true;
}

void Test_Sort() {
	{
		const int SIZE = 9;
		int ar[SIZE] = {1,3,0,-1,6,9,2,1,7};
		BubbleSort(&ar[0], SIZE);
		std::cout << "array is " << (CheckSort(ar, SIZE) == true ? "descending" : "not sorted") << std::endl;
	}


}

int main(int argc, char** argv) {

	Test_Sort();	

	const int SIZE = 10;
	int ar[SIZE] = {1,-2,3,0,-1,6,21,2,1,7};

	for (int i = 0; i < SIZE; std::cout << ar[i++] << " ");
	std::cout << std::endl;

	BubbleSort(ar, SIZE, [](int a, int) {return (a % 2) == 0;});

	for (int i = 0; i < SIZE; std::cout << ar[i++] << " ");
	std::cout << std::endl;

    return 0;
}



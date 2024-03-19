#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <assert.h>
//#include <string.h>

#include "sorts.h"
#include "test.h"

//int global = 100;

bool temp_comp(int a, int b) {
	return a > b;
}

void BubbleSort(int* ar, size_t size, bool (*comp)(int, int) = [](int a, int b){return a < b;}) {
	int i = 0;
	int j = 0;

	while (j < size) {
		i = 0;
		while (i < size - 1 - j) {
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
	bool asc = false;
	int i = 0;
	while (ar[i] == ar[i+1] && i < size - 1) {
		i++;
	}
	if (i == size - 1) {
		return true;
	}

	if (ar[i] < ar[i+1]) {
		asc = true;
	}
	
	for (; i < size - 1; i++) {
		if (ar[i] > ar[i+1] && asc == true) {
			return false;
		}
		if (ar[i] < ar[i+1] && asc == false) {
			return false;
		}
	}
	return true;
}

void Test_checkSort() {
	{
		int ar[10] = {1,2,3,4,5,6,7,8,9,10};
		ASSERT(CheckSort(ar, 10) == true);
	}	
	{
		int ar[10] = {10,9,8,7,6,5,4,3,2,1};
		ASSERT(CheckSort(ar, 10) == true);
	}
	{
		int ar[10] = {1,1,1,1,1,1,1,1,1,1};
		ASSERT(CheckSort(ar, 10) == true);
	}
	{
		int ar[10] = {1,1,0,0,0,0,0,-3,-4,-5};
		ASSERT(CheckSort(ar, 10) == true);
	}
	{
		int ar[10] = {1,1,1,2,2,2,3,3,3,10};
		ASSERT(CheckSort(ar, 10) == true);
	}
	{
		int ar[10] = {1,1,1,2,4,2,3,3,3,10};
		ASSERT(CheckSort(ar, 10) == false);
	}
	{
		int ar[10] = {1,1,1,2,4,2,3,3,3,10};
		ASSERT_HINT(CheckSort(ar, 1) == true, "array have only one element");
	}
}


void Test_Sort() {
	{
		const int SIZE = 9;
		int ar[SIZE] = {1,3,0,-1,6,9,2,1,7};
		BubbleSort(&ar[0], SIZE);
		ASSERT(CheckSort(ar, SIZE));
	}
}

void hard_function() {

}

int main(int argc, char** argv) {
	RUN_TEST(Test_checkSort);
	RUN_TEST(Test_Sort);

	return 0;
	assert(10 == 10);
	float temp = 9/10;
	ASSERT_HINT(0.9 == temp, "compare 0.9 with 9/10");
	ASSERT(0.9 == temp);
	ASSERT_HINT(9/10 == temp, "compare 9/10 with 9/10");

	std::cout << "all is okeushki..." << std::endl;
	return 0;

	Test_Sort();	

	const int SIZE = 10;
	int ar[SIZE] = {1,-2,3,0,-1,6,21,2,1,7};


	for (int i = 0; i < SIZE; std::cout << ar[i++] << " ");
	std::cout << std::endl;

	auto pf = [](int a, int b){ 
		static int count = 0;
		std::cout << count++ << " : " << a << " " << b << std::endl;
		return a > b;
	};

	BubbleSort(ar, SIZE, pf ); 

	for (int i = 0; i < SIZE; std::cout << ar[i++] << " ");
	std::cout << std::endl;

    return 0;
}



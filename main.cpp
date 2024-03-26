#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <assert.h>
//#include <string.h>
#include <bitset>
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

union Numbers {
	int num_i;
	float num_f;
};

void test(char* t) {
	char* t1 = new char [128];
	t = t1;
}

void test1(char** t) {
	char* t1 = new char [128];
	*t = t1;
}

int main(int argc, char** argv) {
	std::cout << __LINE__ << " " << __func__ << " " << __FILE__ << std::endl;
	RUN_TEST(Test_checkSort);
	RUN_TEST(Test_Sort);

	Numbers temp;
	temp.num_f = 72.9876120;
	//temp.num_i |= (1 << 31);

	std::cout << temp.num_f << " = " << temp.num_i << " " << std::bitset<32>(temp.num_i) << std::endl;
	temp.num_i++;
	std::cout << temp.num_f << " = " << temp.num_i << " " << std::bitset<32>(temp.num_i) << std::endl;

	int temp1 = (int)(temp.num_f);
	std::cout << temp1 << std::endl;


    return 0;
}



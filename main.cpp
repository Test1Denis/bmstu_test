#include <algorithm>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string.h>
#include <bitset>


int binSearch(const int* array, size_t size, int element) {
	
	int central_element = array[size/2];
	if (element == central_element) {
		return size/2;
	}

	if (size <= 1) {
		return -1;
	}
	
	if (array[size/2] > element) {
		int res = binSearch(array, size/2, element);
		if (res < 0) {
			return -1;
		}
		return res;
	}

	if (array[size/2] < element) {
		int res = binSearch(&array[size/2], size - size/2, element);
		return res < 0 ? -1 : res + size/2;
	}

}
	
void test_binSearch() {
/*	{
		int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::cout << binSearch(ar, 20, 0) << std::endl;	
	}	
	{
		int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::cout << binSearch(ar, 20, 21) << std::endl;	
	}	
*/
/*
	{
		int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::cout << binSearch(ar, 20, 1) << std::endl;	
	}	
	{
		int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::cout << binSearch(ar, 20, 2) << std::endl;	
	}	
	{
		int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::cout << binSearch(ar, 20, 3) << std::endl;	
	}	
	{
		int ar[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		std::cout << binSearch(ar, 20, 4) << std::endl;	
	}	
*/
	{
		int ar[] = {1,2,3,4,5,6,7,8,9,11,11,12,13,14,15,16,17,18,19,20};
		for (int i = 0; i < 22; i++) {
			int index = binSearch(ar, 20, i);
			std::cout << i << ": index =  " << index << " element = " << ar[index]  << std::endl;	
		}
	}	
	{
		std::cout << "---------------" << std::endl;
		int ar[] = {1,5,5,5,5,5,5,8,9,10,10,13,13,15,15,15,17,18,19,20};
		for (int i = 0; i < 22; i++) {
			int index = binSearch(ar, 24, i);
			std::cout << i << ": index =  " << index << " element = " << ar[index]  << std::endl;	
		}
	}	
}

int main() {
	test_binSearch();
	return 0;
}

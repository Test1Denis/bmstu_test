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
	std::cout << "ona ploxo rabotaet " << __func__ << std::endl;
}

int GetMaxInd(const int* ar, int size) {
	int indMax = 0;
	
	for (int i = 1; i < size; i++) {
		indMax = (ar[i] < ar[indMax]) ? indMax : i;
	}

	return indMax;
}

void SelectionSort(int *ar, int size) {
	std::cout << __FILE__ << " : " << __func__ << std::endl;
	for (int i = 0; i < size; i++) {
		int ind = GetMaxInd(&ar[i], size - i) + i;
		std::swap(ar[ind], ar[i]);
	}
}

void TestSort(void (*sort)(int*, int), const char* func_name) {
	std::cout << func_name << " start test" << std::endl;
	{
		int ar[17] = {17,1,2,9,0,-1,6,6,2,8,7,3,6,6,6,9000, 9};
		sort(ar, 17);
		std::cout << std::dec << "\t\t";
		for (int i = 0; i < 17; std::cout << ar[i++] << " ");
		std::cout << std::endl;
	}

}

void QuickSort(int*, int) {
	std::cout << __func__ << std::endl;
}

void MergeSort(int*, int) {
	std::cout << __func__ << std::endl;
}


int main(int argc, char** argv) {
	int a = -1;
	if (argc > 1) {
//		itoa -- convert integer to string
//	atoi -- convert str to int
		a = atoi(argv[1]);
	}
	GetA_doitany(a);

	void (*sorts[])(int*, int) = {SelectionSort, BubbleSort, QuickSort, MergeSort};
	char* name_sorts[] = {"SelectionSort", "BubbleSort", "QuickSort", "MergeSort"};
	for (int i = 0; i < 4; i++) {
		TestSort(sorts[i], name_sorts[i]);
	}
/*
	TestSort(SelectionSort, "SelectionSort");
	TestSort(BubbleSort, "BubbleSort");
	TestSort(QuickSort, "QuickSort");
	TestSort(MergeSort, "MergeSort");
*/
		
    return 0;
}


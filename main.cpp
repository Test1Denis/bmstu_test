#include <algorithm>
#include <iostream>
#include <fstream>
#include <assert.h>
#include <string.h>
#include <bitset>

	
int GetMin(const int* ar, int size) {

	if (size == 1) {
		return ar[0];
	}

	if (ar[0] > ar[size - 1]) {
		return GetMin(&ar[1], size - 1);			
	}
	return GetMin(ar, size-1);
}


struct ParamAr {
	int min;
	int max;
	double aver;

	ParamAr();
};

ParamAr::ParamAr() {
	min = ~(1 << 31);	//here we will put maxima value of integer!!!
	max = 1 << 31;		//here maxima value of integer is put
	aver = 0;
}

ParamAr GetParamAr(const int* ar, size_t size) {
	ParamAr param;
	
//	for (int left = 0, right = size - 1; left < right; left++, right--) {}
	auto getMin = [](int a, int b){ return a > b ? b : a; };
	auto getMax = [](int a, int b){ return a > b ? a : b; };	// [](){};

	for (int i = 0; i < size; i++) {
		param.max = getMax(param.max, ar[i]);
		param.min = getMin(param.min, ar[i]);
		param.aver += (double)ar[i] / (double)size;
		
	}

	return param;
}

std::ostream& operator<<(std::ostream& out, const ParamAr& input) {
	out << " aver = " << input.aver 
		<< " min = " << input.min 
		<< " max = " << input.max << std::endl;
	return out;
}

int main() {

	int ar[10] = {1,2,3,4,-1,5,6,7,8,9};
	std::cout << GetMin(ar, 10) << std::endl;
	std::cout << GetParamAr(ar, 10);
	return 0;
}

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
	int size;

	ParamAr();
};

ParamAr::ParamAr() {
	min = ~(1 << 31);	//here we will put maxima value of integer!!!
	max = 1 << 31;		//here maxima value of integer is put
	aver = 0;
	size = -1;
}

ParamAr GetParamAr(const int* ar, size_t size, struct ParamAr param) {
	param.size = size > param.size ? size : param.size;

	if (size == 0) {
		param.aver = (double)param.aver / (double)param.size;	
		return param;
	}	
	

	auto getMin = [](int a, int b){ return a > b ? b : a; };
	auto getMax = [](int a, int b){ return a > b ? a : b; };	// [](){};

	param.max = getMax(param.max, ar[0]);
	param.min = getMin(param.min, ar[0]);
	param.aver += (double)ar[0];

	ParamAr tempParam = GetParamAr(&ar[1], size-1, param);

	return tempParam;
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
	ParamAr temp;
	std::cout << GetParamAr(ar, 10, temp);
	std::cout << std::endl;
	return 0;
}

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
//#include <string.h>

#include "sorts.h"

void CreateMatrix() {
	char** matrix;

	int size_str = 10;
	matrix = new char *[16];
	for (int i = 0; i < 16; i++) {
		matrix[i] = new char [size_str];
		size_str += random() % 20;
	}

	//work....

	for (int i = 0; i < 16; i++) {
		delete [] matrix[i];
	}
	delete [] matrix;
}

int GetFileSize(const char* fileName) {

	return -1;
}

int main(int argc, char** argv) {

	stupidSort(nullptr, 100);
	QuickSort(nullptr, 100);
	
	FILE* f = fopen("temp_text", "r");

	char* text = new char [1024];
	
	int size_file = fread(text, 1, 1024, f);
	std::cout << "size file = " << size_file << " : " << text << std::endl;
	
	char* t = strtok(text, " .!;");
	t[2] = 'X';
	do { 

		std::cout << t << std::endl;
		t = strtok(nullptr, " .!;");

	}while(t != nullptr);

	delete [] text;

	fclose(f);

	return 0;

	char* myStr = new char [256];
	
	strncpy(myStr, "123456098321", 6);
	strcat(myStr, "test");

	size_t size_str = strlen(myStr);
	std::cout <<  size_str << " : " << myStr << std::endl;

	int rescmp = strcmp("test", myStr);
	std::cout << rescmp << std::endl;

    return 0;
}



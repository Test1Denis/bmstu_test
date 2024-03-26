#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
//#include <string.h>



int main(int argc, char** argv) {

	char myStrg[256];
	char* myStr = new char [256];
	
	strcpy(myStr, "123456098321");
	strcpy(myStr, "test");
	myStr[strlen(myStr)] = 0x33;

	for (int i = 0; i < 256; myStrg[i] = myStrg[i] == 0x00 ? ' ' : myStrg[i], i++);

	size_t size_str = strlen(myStr);
//	std::cout << myStr << " " << size_str << std::endl;
	
	size_str = strlen(myStrg);
	std::cout << myStrg << " " << size_str << std::endl;

    return 0;
}



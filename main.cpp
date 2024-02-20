#include <iostream>

void test(int, int);

int main(int argc, char** argv) {
	for (int i = 0; i < argc; i++) {
		std::cout << i << " " << argv[i] << std::endl;
	}
	
    return 0;
}

void test(int a, int b) {

}

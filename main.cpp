#include <iostream>

#define PRINT(A) (std::cout << (int)A << " : " << (char)A << std::endl)
#define MULT(A, B) ((A) * (B))

int mult(int a, int b) {
	return a*b;
}

int main() {
#ifdef DEBUG
	for (int i = 0; i < 256; i++) {
		PRINT(i);
	}
#endif
#ifdef ABC
	std::cout << "ABC is defined" << std::endl;
	PRINT(MULT(2+2, 7));
#endif
#ifndef ABC
	std::cout << "ABC is NOT defined" << std::endl;
	PRINT(mult(2+2, 5));
#endif
	

    return 0;
}

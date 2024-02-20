#include <iostream>


int main() {

	int b = 894277321;
	int count = 0;

	for (int i = 0; i < sizeof(int) * 8; i++) {
//		count += b & (1 << i) ? 1 : 0;
		count += (b & (1 << i)) >> i;

		//std::cout << std::dec << i << " : " << (unsigned int)(1 << i)  << "\t" 
		//			<< std::hex << (1 << i) << std::endl;
	}

	std::cout << "one bit in " << std::hex <<  b << " = " << count << std::endl;


    return 0;
}

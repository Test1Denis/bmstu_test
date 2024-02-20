#include <iostream>

#define PRINT(A) (std::cout << A)

int main() {
	PRINT(100);
	

	int b = 894277321;

	b = 0xFF;
	b &= ~(0x30 << 4);	//reset 3 bit
	std::cout << std::hex << b << std::endl;
	b |= (1 << 3);
	std::cout << std::hex << b << std::endl;
	return 0;

	int count = 0;

	for (int i = 0; i < sizeof(int) * 8; i++) {
		count += (b & (1 << i)) >> i; //count += b & (1 << i) ? 1 : 0;
	}

	std::cout << "one bit in " << std::hex <<  b << " = " << count << std::endl;


    return 0;
}

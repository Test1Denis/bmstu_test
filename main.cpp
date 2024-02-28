#include <algorithm>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {

	FILE* f = fopen("test_file", "w");

	unsigned int* ar = new unsigned int [20] {1,2,3,4,5,6,7,8,9,10,1000,2000,3030,4040,5050,606060, 0xAABBCCDD, 0xFFF0000, 18, 19};	
		
	fwrite(ar, 20, 4, f);
	fwrite(ar, 80, 1, f);
	fwrite(ar, 1, 80, f);

	delete [] ar;
	fclose(f);

	
	f = fopen("parabolllla", "a");
		
	int curr_pos = ftell(f);
	std::cout << curr_pos << std::endl;
	fseek(f, 0x00, SEEK_SET);
	
	curr_pos = ftell(f);
	std::cout << curr_pos << std::endl;
	fprintf(f, "prlilichnoe 2\n");


	fclose(f);
	return 0;


	float x = -2;
	float y = x*x;
	float step = 4.0/100.0;
	for (int p = 0; p < 100; p++) {
		fprintf(f, "%2.2f\t%2.8f\t%2.2f\n", x, y, y);
		x += step;
		y = x * x;
	}

	fclose(f);

    return 0;
}


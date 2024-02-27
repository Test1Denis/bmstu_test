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

	
	f = fopen("parabolllla", "r");
	char* strParabolllla = new char [20];
	
	while(fread(&strParabolllla[0], 20, 1, f) > 0x00) {
		for (int i = 0; i < 20; std::cout << strParabolllla[i++]);
	}	
	std::cout << std::endl;

	delete [] strParabolllla;
	strParabolllla = nullptr;

	fseek(f, 0x00, SEEK_SET);	//переместиться в начало файла....
	
	float x_read;
	float y_read1, y_read2;

	std::cout << "-------------------------" << std::endl;
	while(fscanf(f, "%f\t%f\t%f\n", &x_read, &y_read1, &y_read2) > 0) {
		std::cout << x_read << "\t" << y_read1 << "\t" << y_read2 << std::endl;
	}

		

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


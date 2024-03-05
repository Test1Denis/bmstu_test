all : main.o sorts.o test.o
	g++ main.o sorts.o test.o -g


main.o : main.cpp
	g++ -c main.cpp -g

sorts.o : sorts.cpp sorts.h
	g++ -c -g sorts.cpp

test.o : test.cpp
	g++ -c -g test.cpp


clean :
	rm -rf *.o a.out

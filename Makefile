all : main.o sorts.o
	g++ main.o sorts.o -g


main.o : main.cpp
	g++ -c main.cpp -g

sorts.o : sorts.cpp sorts.h
	g++ -c -g sorts.cpp

clean :
	rm -rf *.o a.out

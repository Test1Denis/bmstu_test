all: main.o
	g++ main.o


main.o : main.cpp
	g++ -c main.cpp -g

clean :
	rm -rf *.o

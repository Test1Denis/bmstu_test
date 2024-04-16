all : main.o sorts.o test.o ring_buffer.o filo_1.o
	g++ main.o sorts.o test.o ring_buffer.o filo_1.o -g

main.o : main.cpp
	g++ -c main.cpp -g

sorts.o : sorts.cpp sorts.h
	g++ -c -g sorts.cpp

test.o : test.cpp
	g++ -c -g test.cpp

ring_buffer.o : ring_buffer.cpp
	g++ -c ring_buffer.cpp -g

filo_1.o : filo_1.cpp
	g++ -c filo_1.cpp -g

clean :
	rm -rf *.o a.out

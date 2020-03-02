main: main.o heap.o
	g++ -o main main.o heap.o

heap.o: heap.cpp
	g++ -std=c++11 -c heap.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o
	rm *main
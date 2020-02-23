run: main.o matrix.o
	g++ -o run main.o matrix.o

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp

matrix.o: matrix.cpp
	g++ -std=c++11 -c matrix.cpp

clean:
	rm *.o
	rm run
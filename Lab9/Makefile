run: main.o rb.o
	g++ -o run main.o rb.o -std=c++11
main.o: main.cpp 
	g++ -c main.cpp -std=c++11
rb.o: rb.cpp
	g++ -c rb.cpp -std=c++11
clean:
	rm *.o
	rm run
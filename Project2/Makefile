run: main.o dictionary.o
	g++ -o run main.o dictionary.o

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm *.o
	rm run

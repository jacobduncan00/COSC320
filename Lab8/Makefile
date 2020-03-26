run: bt.o main.o
	g++ -o run bt.o main.o

bt.o: bt.cpp
	g++ -c bt.cpp -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean: 
	rm *.o
	rm run

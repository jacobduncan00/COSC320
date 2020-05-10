run: main.o Graph.o
	g++ -o run main.o Graph.o -std=c++11

Graph.o: Graph.cpp
	g++ -c Graph.cpp -std=c++11

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm *.o
	rm run

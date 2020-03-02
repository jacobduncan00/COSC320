main.exe: main.o HeapPQ.o
	g++ -o main.exe main.o HeapPQ.o 

HeapPQ.o: HeapPQ.cpp
	g++ -c HeapPQ.cpp -std=c++11 

main.o: main.cpp
	g++ -c main.cpp -std=c++11

clean:
	rm *.o
	rm main.exe
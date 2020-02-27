all: productionNeeded.exe driver.exe

driver.exe: main.o matrix.o
	g++ -o driver.exe main.o matrix.o
	
productionNeeded.exe: main2.o matrix.o
	g++ -o productionNeeded.exe main2.o matrix.o

main.o: main.cpp 
	g++ -std=c++11 -c main.cpp

main2.o: main2.cpp
	g++ -std=c++11 -c main2.cpp

matrix.o: Matrix.cpp
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm *.o
	rm productionNeeded.exe
	rm driver.exe
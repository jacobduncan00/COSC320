all: 3D.exe 2D.exe Subroutine.exe

3D.exe: 3D.o matrix.o
	g++ -o 3D.exe 3D.o matrix.o 

2D.exe: 2D.o matrix.o
	g++ -o 2D.exe 2D.o matrix.o 

Subroutine.exe: subroutine.o matrix.o
	g++ -o Subroutine.exe subroutine.o matrix.o

2D.o: 2D.cpp
	g++ -c 2D.cpp -std=c++11

3D.o: 3D.cpp
	g++ -c 3D.cpp -std=c++11

subroutine.o: subroutine.cpp
	g++ -c subroutine.cpp -std=c++11

matrix.o: matrix.cpp
	g++ -c matrix.cpp -std=c++11

clean:
	rm *.o
	rm *.exe 

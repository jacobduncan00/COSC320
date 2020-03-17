all: iomodel driver 

iomodel: iomodel.o Matrix.o
	g++ -o iomodel iomodel.o Matrix.o

driver: driver.o Matrix.o
	g++ -o driver driver.o Matrix.o

driver.o: driver.cpp
	g++ -std=c++11 -c driver.cpp

iomodel.o: iomodel.cpp
	g++ -std=c++11 -c iomodel.cpp

Matrix.o: Matrix.cpp
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm *.o
	rm iomodel
	rm driver

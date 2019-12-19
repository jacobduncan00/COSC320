#include <iostream>
#include "matrix.h"

int main(){

	int sourceA[] = {1, 2, 3, 4, 5, 6};
	Matrix matA(2,3);
	matA.populateMatrix(sourceA, 6);

	matA.printMatrix();
	std::cout << "A" << std::endl;
	matA.tran(); // PROBLEM
	std::cout << "A" << std::endl;
	matA.printMatrix();
}
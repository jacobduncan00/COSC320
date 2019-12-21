#include <iostream>
#include "matrix.h"

int main(){

	// First Matrix
	int sourceA[] = {1, 2, 3, 4, 5, 6};
	Matrix matA(2,3);
	matA.populateMatrix(sourceA, 6);

	// Second Matrix
	int sourceB[] = {6, 5, 4, 3, 2, 1};
	Matrix matB(2,3);
	matB.populateMatrix(sourceB, 6);

	std::cout << "Printing Matrix A" << std::endl;
	std::cout << std::endl;
	matA.printMatrix();
	std::cout << std::endl;

	std::cout << "Printing Matrix B" << std::endl;
	std::cout << std::endl;
	matB.printMatrix();
	std::cout << std::endl;

	std::cout << "Transposing Matrix A..." << std::endl;
	matA.tran();
	std::cout << std::endl;
	std::cout << "Printing Matrix A" << std::endl;
	std::cout << std::endl;
	matA.printMatrix();
	std::cout << std::endl;

	std::cout << "Transposing Matrix B..." << std::endl;
	matB.tran();
	std::cout << std::endl;
	std::cout << "Printing Matrix B" << std::endl;
	std::cout << std::endl;
	matB.printMatrix();
	std::cout << std::endl;

	std::cout << "Adding Matrix A & Matrix B..." << std::endl;
	matA.add(matB);
	std::cout << std::endl;
	matA.printMatrix();
	std::cout << std::endl;

	// Third Matrix
	int sourceC[] = {2, 3, 4, 5, 6, 7};
	Matrix matC(2,3);
	matC.populateMatrix(sourceC, 6);

	// Fourth Matrix
	int sourceD[] = {1, 2, 3, 4, 5, 6};
	Matrix matD(2,3);
	matD.populateMatrix(sourceD, 6);

	std::cout << "Printing Matrix C" << std::endl;
	std::cout << std::endl;
	matC.printMatrix();
	std::cout << std::endl;

	std::cout << "Printing Matrix D" << std::endl;
	std::cout << std::endl;
	matD.printMatrix();
	std::cout << std::endl;

	std::cout << "Transposing Matrix C..." << std::endl;
	matC.tran();
	std::cout << std::endl;
	std::cout << "Printing Matrix C" << std::endl;
	std::cout << std::endl;
	matC.printMatrix();
	std::cout << std::endl;

	std::cout << "Transposing Matrix D..." << std::endl;
	matD.tran();
	std::cout << std::endl;
	std::cout << "Printing Matrix D" << std::endl;
	std::cout << std::endl;
	matD.printMatrix();
	std::cout << std::endl;

	std::cout << "Subtracting Matrix C & Matrix D..." << std::endl;
	matC.sub(matD);
	std::cout << std::endl;
	matC.printMatrix();
	std::cout << std::endl;

	// Fifth Matrix
	int sourceE[] = {1, 2, 3, 4, 5, 6};
	Matrix matE(2,3);
	matE.populateMatrix(sourceE, 6);

	// Sixth Matrix
	int sourceF[] = {1, 2, 3, 4, 5, 6};
	Matrix matF(3, 2);
	matF.populateMatrix(sourceF, 6);

	std::cout << "Printing Matrix E" << std::endl;
	std::cout << std::endl;
	matE.printMatrix();
	std::cout << std::endl;

	std::cout << "Printing Matrix F" << std::endl;
	std::cout << std::endl;
	matF.printMatrix();
	std::cout << std::endl;

	std::cout << "Multiplying Matrix E & Matrix F..." << std::endl;
	matE.mult(matF);
	std::cout << std::endl;
	matE.printMatrix();
	std::cout << std::endl;
}
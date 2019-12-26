#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "matrix.h"


bool store(std::string fileName, std::vector<float> & vecOfFloatX, std::vector<float> & vecOfFloatY){
  std::ifstream inFile;
  inFile.open(fileName);
  if(!inFile){
    std::cerr << "Cannot open the file: " << fileName << std::endl;
    return false;
  }
  else{
    float xVal = 0;
		float yVal = 0;
    for (int i = 0; i < 100; i++){
				inFile >> xVal;
        inFile >> yVal;
				vecOfFloatX.push_back(xVal);
        vecOfFloatY.push_back(yVal);
      }
      inFile.close();
      return true;
      }
    }

int main(){
	/*
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
	Matrix matF(3,2);
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

	int sourceG[] = {1, 2, 3, 4, 5, 6,};
	Matrix matG(2,3);
	matG.populateMatrix(sourceG, 6);

	std::cout << "Printing Matrix G" << std::endl;
	std::cout << std::endl;
	matG.printMatrix();
	std::cout << std::endl;
	std::cout << "Scalar multiplication by 2 on Matrix G" << std::endl;
	matG.scalarMult(matG, 2);
	std::cout << std::endl;
	std::cout << "Printing Matrix G" << std::endl;
	std::cout << std::endl;
	matG.printMatrix();
	std::cout << std::endl;

	*/
	std::vector<float> vecOfFloatX;
	std::vector<float> vecOfFloatY;
	bool result = store("points100.txt", vecOfFloatX, vecOfFloatY);
	Matrix matAlpha(10,10);
	matAlpha.populateMatrix(vecOfFloatX, 100);
	std::cout << "Printing Matrix of X-Values" << std::endl;
	std::cout << std::endl;
	matAlpha.printMatrix();
	std::cout << std::endl;

	Matrix matBeta(10,10);
	matBeta.populateMatrix(vecOfFloatY, 100);
	std::cout << "Printing Matrix of Y-Values" << std::endl;
	std::cout << std::endl;
	matBeta.printMatrix();
	std::cout << std::endl;
}

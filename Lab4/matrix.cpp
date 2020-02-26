#include <iostream>
#include <iomanip>
#include <math.h>
#include "matrix.h"

#define RESET "\033[0m"
#define WHITE "\033[37m" 
#define PURPLE "\033[35m"
#define RED "\033[31m" 

Matrix::Matrix() : rows(10), cols(10) {
    mat = new long unsigned int*[rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new long unsigned int[cols];
    }
    mat[0][0] = 0;
}

Matrix::Matrix(unsigned long int row, unsigned long int col){
  if (row < 1 || col < 1){
    std::cout << "Invalid Matrix Size" << std::endl;
    exit(1);
  } 
  rows = row;
  cols = col;
  mat = new long unsigned int*[row];
  srand(time(NULL));
    for(int i = 0; i < rows; i++){
      mat[i] = new long unsigned int[cols];
      for (int j = 0; j < cols; j++){
        mat[i][j] = (rand()%99)+1; // for testing purposes 0-4
      }
    }
}


Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  long unsigned int** arr = new long unsigned int*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new long unsigned int[cols];
  }
  mat = arr;
  for(int i = 0; i < m.rows; i++){
    for(int j = 0; j < cols; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
}

Matrix::~Matrix(){
  for(int i = 0; i < this -> rows; i++){
    delete[] this -> mat[i];
  }
  delete[] this -> mat;
}

void Matrix::identityMatrix(){
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = 1;
  }
}

void Matrix::diagonalMatrix(){
  srand(time(NULL));
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = 999;
  }
}

void Matrix::triangularMatrix(bool up){
  srand(time(NULL));
  if(up){
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->rows; j++){
        if(i < j){
          this->mat[i][j] = 999;
        }
        else{
          this->mat[i][j] = 0;
        }
      }
    }
  }
  else{
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->rows; j++){
        if(i > j){
          this->mat[i][j] = 999;
        }
        else{
          this->mat[i][j] = 0;
        }
      }
    }
  }
}

void Matrix::printMatrix(){
    for(int i = 0; i < this->rows; i++){
        if(i != 0)
            std::cout << std::endl;
        for(int j = 0; j < this->cols; j++){
            if(this->mat[i][j] == 999){
              std::cout << std::setfill('0') << std::setw(3) << RED << this->mat[i][j] << " " << RESET;
            }
            else if(this->mat[i][j] == 1){
              std::cout << std::setfill('0') << std::setw(3) << RED << "001" << " " << RESET;
            }
            else{
              std::cout << std::setfill('0') << std::setw(3) << this->mat[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::operator=(const Matrix& m){
  Matrix copy(m);
  rows = m.rows;
  cols = m.cols;
  long unsigned int** arr = new long unsigned int*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new long unsigned int[cols];
  }
  mat = arr;
  long unsigned int** temp = mat;
  mat = copy.mat;
  copy.mat = temp;
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix){
    for(int i = 0; i < matrix.rows; i++){
        for(int k = 0; k < matrix.cols; k++)
            os << matrix.mat[i][k] << " ";
        std::cout << "\n";
        }
        return os;
}

Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows != matrixb.rows || matrixa.cols != matrixb.cols){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}

	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixa.cols; k++) 
			matrixc.mat[i][k] = matrixa.mat[i][k] + matrixb.mat[i][k];
	return matrixc;
}

Matrix operator- (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows!= matrixb.rows|| matrixa.cols != matrixb.cols){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}

	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows;i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixc.mat[i][k] = matrixa.mat[i][k] - matrixb.mat[i][k];
	return matrixc;
}

Matrix operator* (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.cols != matrixb.rows){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}
	Matrix matrixc(matrixa.rows, matrixb.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixb.cols; k++)
			for(int p = 0; p < matrixb.rows; p++)
				matrixc.mat[i][k] += (matrixa.mat[i][p] * matrixb.mat[p][k]);

	return matrixc;
}

Matrix operator* (const long unsigned int& c, const Matrix& matrixa){ // Scalar Mult.
	Matrix matrixb(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixb.mat[i][k] = (matrixa.mat[i][k] * c);

	return matrixb;
}

Matrix operator^ (const Matrix& m, const char& exp){
	Matrix matrixb(m.cols, m.rows);
	for(int i = 0; i < m.rows; i++)
		for(int j = 0; j < m.cols; j++)
			matrixb.mat[j][i] = m.mat[i][j];

	return matrixb;
}

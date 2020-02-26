#include <iostream>
#include <iomanip>
#include <math.h>
#include <chrono>
#include "matrix.h"

#define RESET "\033[0m"
#define WHITE "\033[37m" 
#define PURPLE "\033[35m"
#define RED "\033[31m" 

Matrix::Matrix() : rows(10), cols(10) { // default constructor which generates a 10x10 matrix with 0's
    mat = new long int*[rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new long int[cols];
    }
    mat[0][0] = 0;
}

Matrix::Matrix(unsigned long int row, unsigned long int col){ // constructor that takes in rows,cols parameter to set the size of matrix with 
  if (row < 1 || col < 1){                                    // values from 1-99
    std::cout << "Invalid Matrix Size" << std::endl;
    exit(1);
  } 
  rows = row;
  cols = col;
  mat = new long int*[row];
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);
    for(int i = 0; i < rows; i++){
      mat[i] = new long int[cols];
      for (int j = 0; j < cols; j++){
        mat[i][j] = (rand()%99)+1; 
      }
    }
}


Matrix::Matrix(const Matrix& m){ // copy constructor, used along side overloaded= operator
  rows = m.rows;
  cols = m.cols;
  long int** arr = new long int*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new long int[cols];
  }
  mat = arr;
  for(int i = 0; i < m.rows; i++){
    for(int j = 0; j < cols; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
}

Matrix::~Matrix(){ // destructor that deallocates the memory used by making "new" 2d arrays
  for(int i = 0; i < this -> rows; i++){
    delete[] this -> mat[i];
  }
  delete[] this -> mat;
}

void Matrix::identityMatrix(){ // identity Matrix function that makes an identity matrix meaning 1's going down the main diagonal
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = 1;
  }
}

void Matrix::diagonalMatrix(){ // diagonal Matrix function that makes the main diagonal all the same number, in this case 999 
  srand(time(NULL));
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = 999;
  }
}

void Matrix::triangularMatrix(bool up){ // triangular Matrix function, depending on the parameter will create a lower or upper triangle within the Matrix
  srand(time(NULL));
  if(up){ // if up == true, then create an upper triangle matrix, meaning if i < j, then assign 999, else assign 0
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
  else{ // else if up == false, then create a lower triangle matrix, meaning if i > j, then assign 999, else assign 0
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

void Matrix::printMatrix(){ // function used to print Matrice's, not needed as I completed the overloaded << operator, however included to use colors
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
            else if(this->mat[i][j] < 0){
              std::cout << std::setw(5) << RED << this->mat[i][j] << " " << RESET;
            }
            else{
              std::cout << std::setfill('0') << std::setw(3) << this->mat[i][j] << " ";
            }
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::operator=(const Matrix& m){ // overloaded assignment operator takes in a Matrix and assigns it's contents to another
  Matrix copy(m);
  rows = m.rows;
  cols = m.cols;
  long int** arr = new long int*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new long int[cols];
  }
  mat = arr;
  long int** temp = mat;
  mat = copy.mat;
  copy.mat = temp;
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix){ // overloaded output stream operator allows me to print Matrices with just std::cout << Matrix;
    for(int i = 0; i < matrix.rows; i++){
        for(int k = 0; k < matrix.cols; k++)
            os << matrix.mat[i][k] << " ";
        std::cout << "\n";
        }
        return os;
}

Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb){ // overloaded addition operator to do Matrix addition, Matrix + Matrix
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

Matrix operator- (const Matrix& matrixa, const Matrix& matrixb){ // overloaded subtraction operator to do Matrix subtraction, Matrix - Matrix
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

Matrix operator* (const Matrix& matrixa, const Matrix& matrixb){ // overloaded multiplication operator to do Matrix multiplication, Matrix x Matrix
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

Matrix operator* (const long unsigned int& c, const Matrix& matrixa){ // Scalar Mult. overloaded operator to do Matrix Scalar multiplication, Matrix x int
	Matrix matrixb(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixb.mat[i][k] = (matrixa.mat[i][k] * c);

	return matrixb;
}

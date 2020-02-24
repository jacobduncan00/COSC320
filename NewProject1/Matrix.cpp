#include <iostream>
#include <iomanip>
#include <math.h>
#include "Matrix.h"

#define RESET "\033[0m"
#define WHITE "\033[37m" 
#define PURPLE "\033[35m"
#define RED "\033[31m" 

Matrix::Matrix() : rows(1), cols(1) {
    mat = new float*[rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new float[cols];
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
  mat = new float*[row];
  srand(time(NULL));
    for(int i = 0; i < rows; i++){
      mat[i] = new float[cols];
      for (int j = 0; j < cols; j++){
        mat[i][j] = (rand()%col)+1; // could be rows too 
      }
    }
}


Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  float** arr = new float*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new float[cols];
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

void Matrix::insert(int i, int j, float num){
  mat[i][j] = num;
}

float Matrix::getVal(int i, int j){
  return mat[i][j];
}

void Matrix::determinant(){
  int det = 0;
  if(rows != cols){
    std::cout << "Matrix is not a square, cannot be invertible" << std::endl;
  }
  if(rows == 2 && cols == 2){
    det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
  }
  else if (rows == 3 && cols == 3){
    det = (mat[0][0] * mat[1][1] * mat[2][2]
			  + mat[0][1]  * mat[1][2] * mat[2][0]
		  	+ mat[0][2]  * mat[1][0] * mat[2][1])
		  	- (mat[0][2] * mat[1][1] * mat[2][0]
		  	+  mat[0][0] * mat[1][2] * mat[2][1]
		  	+  mat[0][1] * mat[1][0] * mat[2][2]);
  }
  else{
    for(int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        det+=mat[i][j];
      }
    }
  }
}

void Matrix::twoDRegression(std::string fileName){
  std::ifstream infile(fileName);
  if(!infile.is_open()){
      	std::cout << "File Opening Error.\n";
      	exit (1);
  }
  int datasize;
  if(fileName == "points100.dat"){
    datasize = 100;
  }
  else if(fileName == "points500.dat"){
    datasize = 500;
  }
  else if(fileName == "points1000.dat"){
    datasize = 1000;
  }
  else if(fileName == "points5000.dat"){
    datasize = 5000;
  }
  else if(fileName == "points10000.dat"){
    datasize = 10000;
  }
  else if(fileName == "points50000.dat"){
    datasize = 50000;
  }
  else if(fileName == "points100000.dat"){
    datasize = 100000;
  }
  else{
    std::cout << "Data Size could not be calculated!" << std::endl;
    return;
  }
  float c1, c2;
  Matrix *A = new Matrix(datasize, 2);
  Matrix *b = new Matrix(datasize, 1);
  for(int i = 0; i < datasize; i++){
    infile >> c1;
    //std::cout << "1st Value: " << c1 << std::endl;
    infile >> c2;
    //std::cout << "2nd Value: " << c2 << std::endl;
    A->insert(i, 0, c1);
    b->insert(i, 0, c2);
    A->insert(i, 1, 1.0);
  }
  infile.close();
  Matrix AT = (*A)^'T';
  Matrix Beta = (((AT * *A).inverse() * AT) * *b);
  std::cout << "[2D] Aβ = [A]*[β]=[x] = b:" << std::endl;
  std::cout << Beta << std::endl; // Prints regression line.
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
  float** arr = new float*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new float[cols];
  }
  mat = arr;
  float** temp = mat;
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

Matrix operator* (const float& c, const Matrix& matrixa){ // Scalar Mult.
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
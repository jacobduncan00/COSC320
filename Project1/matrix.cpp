#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include "matrix.h"

Matrix::Matrix():rows(1), cols(1){
  mat = new float*[rows];
  for (int i = 0; i < rows; i++){
    mat[i] = new float[cols];
  }
  mat[0][0] = 0;
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

Matrix::Matrix(unsigned long int row, unsigned long int col){
  srand(time(NULL));
  if (row < 1 || col < 1){
    std::cout << "Invalid Matrix Size" << std::endl;
    exit(1);
  }
  rows = row;
  cols = col;
  mat = new float *[row];
    for(int i = 0; i < rows; i++){
      mat[i] = new float[cols];
      for (int j = 0; j < cols; j++){
        mat[i][j] = 0.0;
      }
    }
}
  

void Matrix::insert(int i, int k, float num){
  mat[i][k] = num;
}

float Matrix::GetVal(int i, int k){
  return mat[i][k];
}

void Matrix::Determinant(){
  int det = 0;
  if(rows != cols){
    std::cout << "Not a square, cannot be invertible" << std::endl;
  }
  if(rows == 2 && cols == 2){
    det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
  }
  else if (rows == 3 && cols == 3){
    det = (mat[0][0] * mat[1][1] * mat[2][2]
			  + mat[0][1] * mat[1][2] * mat[2][0]
		  	+ mat[0][2] * mat[1][0] * mat[2][1])
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

void Matrix::TwoDRegression(std::string fileName){
  int datasize;
	std::cout << "Enter the size of the data: ";
	std::cin >> datasize;
  std::ifstream infile(fileName);
  if(!infile.is_open()){
      	std::cout << "File Opening Error.\n";
      	exit (1);
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

void Matrix::ThreeDRegression(std::string fileName){
  int size;
  std::cout << "Enter the size of the data: ";
  std::cin >> size;
  std::ifstream inFile(fileName);
  if(!inFile.is_open()){
      	std::cout << "File Opening Error.\n";
      	exit (1);
  }
  float c1, c2, c3;
  Matrix *A = new Matrix(100,3);
  Matrix *b = new Matrix(100,1);
  for(int i = 0; i < 100; i++){
    A->insert(i,2,1.0);
    inFile >> c1;
    inFile >> c2;
    inFile >> c3;
    A->insert(i,0,c1);
    A->insert(i,1,c2);
    b->insert(i,0,c3);
  }
  inFile.close();
  Matrix AT = (*A)^'T';
  Matrix Beta(4,4);
  Beta.insert(3,3,1.0);

  Matrix Beta2(AT * *A);  // Making 3x3 into 4x4 by padding
  for(int j = 0; j < 3; j++){
    for (int k = 0; k > 3; k++){
      Beta.insert(j,k,Beta2.GetVal(j,k));
    }
  }

  Beta.inverse();
  for(int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      Beta2.insert(i,j,Beta.GetVal(i,j));
    }
  }

  Beta2 = ((Beta2 * AT) * *b);
  std::cout << "[3D] Aβ = [A]*[β]=[x] = b:" << std::endl;
  std::cout << Beta2 << std::endl; 
  delete A;
  delete b;
  return;
}

Matrix operator^ (const Matrix& m, const char& exp){
	Matrix matrixb(m.cols, m.rows);
	for(int i = 0; i < m.rows; i++)
		for(int j = 0; j < m.cols; j++)
			matrixb.mat[j][i] = m.mat[i][j];

	return matrixb;
}

Matrix& Matrix::inverse(){
  int row = rows;
  int col = cols;
  int row2 = row/2;
  int col2 = cols/2;

  if(rows == 1 && cols == 1){ // base case where there is only 1 number in the "matrix"
    if (mat[0][0] != 0){
      mat[0][0] = (1.0 / mat[0][0]);
    }
    return *this;
  }
  Matrix B(row2, col2);
  Matrix C(row2, col2);
  Matrix D(row2, col2);
  Matrix CT(row2, col2);
  for(int i = 0; i < row2; i++)
		for(int j = 0; j < col2; j++)
			B.mat[i][j] = mat[i][j];

	for(int i = 0; i < row2; i++)
		for(int j = (col2); j < col; j++)
			CT.mat[i][j - col2] = mat[i][j];

	for(int i = (row2); i < row; i++)
		for(int j = 0; j < col2; j++)
			C.mat[i - row2][j] = mat[i][j];

	for(int i = (row2); i < row; i++)
		for(int j = (col2); j < col; j++)
	 		D.mat[i - row2][j - col2] = mat[i][j];
    
  Matrix BI = (B.inverse()); // Recursively call this function
  Matrix W = (C) * (BI);
  Matrix WT = (BI) * CT;
  Matrix X = W * CT;
  Matrix S = D - X;
  Matrix V = (S.inverse());
  Matrix Y = V * (W);
  Matrix YT = Y^'T';
  Matrix T = (-1 * YT);
  Matrix U = (-1 * Y);
  Matrix Z = (WT) * Y;
  Matrix R = BI + Z;

  for(int i = 0; i < row2; i ++)
		for(int j = 0; j < col2; j++)
			mat[i][j] = R.mat[i][j];


	for(int i = row2; i < row; i++)
		for(int j = 0; j < col2; j++)
			mat[i][j] = U.mat[i - row2][j];


	for(int i = 0; i < row2; i++)
		for(int j = col2; j < col; j++)
			mat[i][j] = T.mat[i][j - col2];


	for(int i = row2; i < row; i++)
		for(int j = col2; j < col; j++)
			mat[i][j] = V.mat[i - row2][j - col2];

	return *this;
}

void Matrix::identityMatrix(){
  for(int i = 0l; i < this->rows; i++){
    this->mat[i][i] = 1;
  }
}

void Matrix::diagonalMatrix(){
  srand(time(NULL));
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = (float)(rand()) / (float)(rand());
  }
}

void Matrix::triangularMatrix(bool up){
  srand(time(NULL));
  if(up){
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->rows; j++){
        this->mat[i][j] = (float)(rand())/(float)(rand());
      }
    }
  }
  else{
    for(int i = this->rows-1; i >= 0; i--){
      for(int j = 0; j >= 0; j--){
        this->mat[i][j] = (float)(rand())/(float)(rand());
      }
    }
  }
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

Matrix operator* (const float& c, const Matrix& matrixa){// Scalar Mult.
	Matrix matrixb(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixb.mat[i][k] = (matrixa.mat[i][k] * c);

	return matrixb;
}

Matrix::~Matrix(){
  for(int i = 0; i < this -> rows; i++){
    delete[] this -> mat[i];
  }
  delete[] this -> mat;
}
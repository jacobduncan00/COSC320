#include <iostream>
#include <iomanip>
#include <math.h>
#include "Matrix.h"

namespace counter{
    int count = 0;
}

Matrix::Matrix(){
    mat = new double*[3];
    for(int i = 0; i < 3; i++){
      mat[i] = new double[3];
    }
    rows = 3;
    cols = 3;
}

Matrix::Matrix(long int row, long int col){
  if (row <= 0 || col <= 0){
    std::cout << "Invalid Matrix Size" << std::endl;
    exit(1);
  } 
  rows = row;
  cols = col;
  mat = new double*[rows];
  srand(time(NULL));
  for(long int i = 0; i < rows; i++){
    mat[i] = new double[cols];
  }
}


Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  double** arr = new double*[rows];
  for(long int i = 0; i < rows; i++){
    arr[i] = new double[cols];
  }
  mat = arr;
  for(long int i = 0; i < m.rows; i++){
    for(long int j = 0; j < cols; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
}

Matrix::~Matrix(){
  for(long int i = 0; i < this->rows; i++){
    delete[] mat[i];
  }
  delete[] mat;
}

Matrix Matrix::fillMatrix(){
  Matrix A = Matrix(rows, cols);
  A.mat[0][0] = 8.0;
	A.mat[0][1] = 3.0;
	A.mat[0][2] = 8.0;
	
	A.mat[1][0] = 4.0;
	A.mat[1][1] = 9.0;
	A.mat[1][2] = 5.0;
	
	A.mat[2][0] = 7.0;
	A.mat[2][1] = 4.0;
	A.mat[2][2] = 7.0;

  return A;
}

Matrix Matrix::fillMatrix2(){
  Matrix A = Matrix(rows, cols);
  A.mat[0][0] = 5.0;
	A.mat[0][1] = 2.0;
	A.mat[0][2] = 3.0;
	
	A.mat[1][0] = 2.0;
	A.mat[1][1] = 6.0;
	A.mat[1][2] = 2.0;
	
	A.mat[2][0] = 3.0;
	A.mat[2][1] = 2.0;
	A.mat[2][2] = 6.0;

  return A;
}

Matrix Matrix::fillMatrix3(){
  Matrix A = Matrix(rows, cols);
  A.mat[0][0] = 5.0;
	A.mat[0][1] = 2.0;
	A.mat[0][2] = 3.0;
  A.mat[0][3] = 9.0;
	
	A.mat[1][0] = 2.0;
	A.mat[1][1] = 6.0;
	A.mat[1][2] = 2.0;
  A.mat[1][3] = 8.0;
	
	A.mat[2][0] = 3.0;
	A.mat[2][1] = 2.0;
	A.mat[2][2] = 6.0;
  A.mat[2][3] = 5.0;

  A.mat[3][0] = 9.0;
	A.mat[3][1] = 5.0;
	A.mat[3][2] = 7.0;
  A.mat[3][3] = 3.0;


  return A;
}

void Matrix::insertNum(int i, int j, double num){
  if((i < 0 || i > this->rows) || (j < 0 || j > this->cols)){
    throw "ERROR: Indeces are not valid.";
  }
  this->mat[i][j] = num;
}

double Matrix::getVal(int i, int j){
  if((i < 0 || i > this->rows) || (j < 0 || j > this->cols)){
    throw "ERROR: Indeces are not valid.";
  }
  return this->mat[i][j];
}

bool Matrix::isSymmetric(){
  Matrix a = *this;
  Matrix b = this->transpose();
  for(long int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(a.mat[i][j] != b.mat[i][j]){ // if the original is not the same as the tranpose, shows symmetry
        return false;
      }
    }
  }
  return true;
}

Matrix Matrix::padMatrix(int d){
	int size = 0;
  while(log2(d + size) - (int)log2(d + size) != 0){
    size++;
  }
  Matrix rtn(d+size, d+size);
  Matrix id(size, size);
  id.identityMatrix();
  for(long int i = 0; i < rtn.rows; i++){
    for(long int j = 0; j < rtn.cols; j++){
      if(i < d && j < d){
        rtn.mat[i][j] = mat[i][j];
      }
      if(i >= d && j >= d){
        rtn.mat[i][j] = id.mat[i-d][j-d];
      }
      if((i >= d && j < d) || (i < d && j >= d)){
        rtn.mat[i][j] = 0;
      }
    }
  }
  return rtn;
}

Matrix Matrix::inverse(){
  // Assuming that "this" is a square (n x n) matrix and is symmetric

  if(rows != cols){
    throw "Not a square matrix!";
  }

  if(rows == 1 || cols == 1){
    Matrix rtn(1,1);
    if(mat[0][0] != 0){
      rtn.mat[0][0] = 1.0/mat[0][0];
    }
    else{
      rtn.mat[0][0] = 0;
    }
    return rtn;
  }

  int ogRow = rows;
  if(log2(rows) - (int)log2(rows) != 0){ // check to see if Matrix is a 2^n x 2^n
    Matrix fixCurr = padMatrix(rows);
    Matrix rtn = fixCurr.inverse();
    Matrix newRtn(ogRow, ogRow);
    for(long int i = 0; i < ogRow; i++){
      for(long int j = 0; j < ogRow; j++){
        newRtn.mat[i][j] = rtn.mat[i][j];
      }
    }
    return newRtn;
  }

  if(!isSymmetric()){
    Matrix temp = *this;
    Matrix temp2 = temp.transpose();
    Matrix temp3 = temp2 * temp;
    Matrix temp4 = temp3.inverse() * temp2;
    return temp4;
  }

	long int row2 = rows/2;
	long int col2 = cols/2;

	Matrix B(row2, col2); // n/2 matrix
	Matrix C(row2, col2); // n/2 matrix
	Matrix CT(row2, col2); // n/2 matrix
	Matrix D(row2, col2); // n/2 matrix

	for(long int i = 0; i < rows; i++){
		for(long int j = 0; j < cols; j++){
			if(i < row2 && j < col2){ //top left
				B.mat[i][j] = mat[i][j];
      }
			if(i < row2 && j >= col2){ //top right
				CT.mat[i][j - col2] = mat[i][j];
      }
			if(i >= row2 && j < col2){ // bottom left
				C.mat[i - row2][j] = mat[i][j];
      }
			if(i >= row2 && j >= col2){ //bottom right
				D.mat[i - row2][j - col2] = mat[i][j];
      }

		}
  }

	Matrix BI = (B.inverse()); // recursively call this function
	Matrix W = (C) * (BI);
  Matrix WT = W.transpose();
	Matrix X = W * CT;
	Matrix S = D - X;
	Matrix V = (S.inverse());
	Matrix Y = V * (W);
	Matrix YT = Y.transpose();
	Matrix T = (YT * -1);
	Matrix U = (Y * -1);
	Matrix Z = (WT) * (Y);
	Matrix R = BI + Z;
  Matrix rtnNew(rows, cols);

  for(long int i = 0; i < rows; i++){
		for(long int j = 0; j < cols; j++){
			if(i < row2 && j < col2){ //top left
				rtnNew.mat[i][j] = R.mat[i][j];
      }
			if(i < row2 && j >= col2){ //top right
				rtnNew.mat[i][j] = T.mat[i][j-col2];
      }
			if(i >= row2 && j < col2){ // bottom left
				rtnNew.mat[i][j] = U.mat[i-row2][j];
      }
			if(i >= row2 && j >= col2){ //bottom right
				rtnNew.mat[i][j] = V.mat[i-row2][j-col2];
      }
		}
  }
	return rtnNew;
}

void Matrix::identityMatrix(){
  Matrix temp(this->rows, this->cols);
  for(long int i = 0; i < this->rows; i++){
    for(long int j = 0; j < this->cols; j++){
      if(i == j){
        mat[i][j] = 1;
      }
      else{
        mat[i][j] = 0;
      }
    }
  }
}

void Matrix::diagonalMatrix(){
  srand(time(NULL));
  for(long int i = 0; i < this->rows; i++){
    this->mat[i][i] = 9;
  }
}

void Matrix::triangularMatrix(bool up){
  srand(time(NULL));
  if(up){
    for(long int i = 0; i < this->rows; i++){
      for(long int j = 0; j < this->rows; j++){
        if(i < j){
          this->mat[i][j] = 9;
        }
        else{
          this->mat[i][j] = 0;
        }
      }
    }
  }
  else{
    for(long int i = 0; i < this->rows; i++){
      for(long int j = 0; j < this->rows; j++){
        if(i > j){
          this->mat[i][j] = 9;
        }
        else{
          this->mat[i][j] = 0;
        }
      }
    }
  }
}

void Matrix::inversePrint(){ // this is a shitty way of doing it by just "rounding" the # but I don't know what else to do...
  for(long int i = 0; i < this->rows; i++){
        if(i != 0)
            std::cout << std::endl;
        for(long int j = 0; j < this->cols; j++){
          if(this->mat[i][j] > 0 && this->mat[i][j] < 1){
            std::cout << std::setw(5) << 0 << " ";
          }
          else if(this->mat[i][j] > -1 && this->mat[i][j] < 0){
            std::cout << std::setw(5) << 0 << " ";
          }
          else{
              std::cout << std::setw(5) << this->mat[i][j] << " ";
        }
    }
  }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::printMatrix(){
    for(long int i = 0; i < this->rows; i++){
        if(i != 0)
            std::cout << std::endl;
        for(long int j = 0; j < this->cols; j++){
              std::cout << std::setw(5) << this->mat[i][j] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

int Matrix::printCounter(){
  return counter::count;
}

Matrix& Matrix::operator=(const Matrix& m){
  if(this == &m){ // when matrices are already the same
    return *this;
  }
  for(long int i = 0; i < rows; i++){
    delete[] mat[i];
  }
  delete[] mat;
  mat = new double*[m.rows];
  for(long int i = 0; i < m.rows; i++){
    mat[i] = new double[m.cols];
  }
  rows = m.rows;
  cols = m.cols;
  for(long int i = 0; i < rows; i++){
    for(long int j = 0; j < cols; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
  counter::count++;
  return *this;
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix){
    for(long int i = 0; i < matrix.rows; i++){
        for(long int k = 0; k < matrix.cols; k++){
            os << matrix.mat[i][k] << " ";
        }
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
	for(long int i = 0; i < matrixa.rows; i++){
		for(long int k = 0; k < matrixa.cols; k++){
			matrixc.mat[i][k] = matrixa.mat[i][k] + matrixb.mat[i][k];
    }
  }
  counter::count++;
	return matrixc;
}

Matrix operator- (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows!= matrixb.rows|| matrixa.cols != matrixb.cols){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}
	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(long int i = 0; i < matrixa.rows;i++){
		for(long int k = 0; k < matrixa.cols; k++){
			matrixc.mat[i][k] = matrixa.mat[i][k] - matrixb.mat[i][k];
    }
  }
  counter::count++;
	return matrixc;
}

Matrix operator* (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.cols != matrixb.rows){
		std::cout << "Invalid matrix size combination.";
		exit(1);
	}
	Matrix matrixc(matrixa.rows, matrixb.cols);
	for(long int i = 0; i < matrixa.rows; i++){
		for(long int j = 0; j < matrixb.cols; j++){
      double sum = 0.0;
      for(long int l = 0; l < matrixa.cols; l++){
        sum += matrixa.mat[i][l] * matrixb.mat[l][j];
      }
      matrixc.mat[i][j] = sum;
    }
  }
  counter::count++;
	return matrixc;
}

Matrix operator* (const Matrix& matrixa, const double& c){ // Scalar Mult.
	Matrix matrixb(matrixa.rows, matrixa.cols);
	for(long int i = 0; i < matrixa.rows; i++){
		for(long int k = 0; k < matrixa.cols; k++){
			matrixb.mat[i][k] = (matrixa.mat[i][k] * c);
    }
  }
  counter::count++;
	return matrixb;
}

Matrix Matrix::transpose(){ // Tranpose function
	Matrix transpose(cols, rows);
	for(long int i = 0; i < rows; i++){
		for(long int j = 0; j < cols; j++){
			transpose.mat[j][i] = mat[i][j];
    }
  }
  counter::count++;
	return transpose;
}
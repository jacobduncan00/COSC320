#include "matrix.h"
#include <iostream>

Matrix::~Matrix(){
  for(int i = 0; i < this -> rows; i++){
    delete[] this -> mat[i];
  }
  delete[] this -> mat;
}

int **Matrix::genMatrix(int rows, int cols){
  int **tempMat = new int*[rows];

  for (int i = 0; i < rows; ++i){
    tempMat[i] = new int[cols];
  }

  return tempMat;
}

void Matrix::printMatrix(){
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j){
      std::cout << this -> mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Matrix::tran(){
  int **temp = genMatrix(this -> cols, this -> rows);

  for (int i = 0; i < this -> cols; ++i){
    for (int j = 0; j < this -> rows; ++j){
      temp[i][j] = this -> mat[j][i];
    }
  }

  for (int i = 0; i < this -> rows; ++i){
    delete[] this -> mat[i];
  }
  //delete[] this -> mat;

  this -> mat = temp;

  int tmp = this -> rows;
  this -> rows = this -> cols;
  this -> cols = tmp;
  std::cout << "Transpose complete!" << std::endl;
}

void Matrix::populateMatrix(int* src, int size){
  if (rows * cols != size){
    std::cout << "Size of Matrix is not equal to size of source array!" << std::endl;
    return;
  }
  int pos = 0;
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j){
      this -> mat[i][j] = src[pos++];
    }
  }
}

void Matrix::add(Matrix& m){
  if (this -> rows != m.getNumRows() || this -> cols != m.getNumCols()){
    std::cout << "ERROR: Matrices are not same size" << std::endl;
  }
  for (int i = 0; i < this -> rows; ++i){
    for (int j = 0; j < this -> cols; ++j){
      this -> mat[i][j] += m.getValueAt(i,j);
    }
  }
  std::cout << "Addition of Matrices complete!" << std::endl;
}

void Matrix::sub(Matrix& m){
 if (this -> rows != m.getNumRows() || this -> cols != m.getNumCols()){
  std::cout << "ERROR: Matrices are not same size" << std::endl;
  }
  for (int i = 0; i < this -> rows; ++i){
    for (int j = 0; j < this -> cols; ++j){
      this -> mat[i][j] -= m.getValueAt(i,j);
    }
  }
  std::cout << "Subtraction of Matrices complete!" << std::endl;
}

void Matrix::mult(Matrix& m){
  if (this -> cols != m.getNumRows()){
    std::cout << "ERROR: Can not multiply these matrices" << std::endl;
  }

  int** result = genMatrix(this -> rows, m.getNumCols());
  for (int i = 0; i < this -> rows; ++i){
    for (int j = 0; j < m.getNumCols(); ++j){
      result[i][j] = 0;
    }
  }

  for (int i = 0; i < this -> rows; ++i){
    for (int j = 0; j < this -> cols; ++j){
      for (int k = 0; k < this -> cols; ++k){
        result[i][j] += this -> mat[i][k] * m.getValueAt(k,j);
      }
    }
  }

  for (int i = 0; i < this -> rows; ++i){
    delete[] this -> mat[i];
  }

  this -> mat = result;
  this -> cols = m.getNumCols();
  std::cout << "Multiplication of Matrices complete!" << std::endl;
}

/*
void Matrix::div(Matrix& m){

}
*/

int Matrix::getValueAt(int i, int j){
  return this -> mat[i][j];
}

int Matrix::getNumRows(){
  return this -> rows;
}

int Matrix::getNumCols(){
  return this -> cols;
}
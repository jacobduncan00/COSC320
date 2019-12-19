#include "matrix.h"
#include <iostream>

Matrix::~Matrix(){
  for(int i = 0; i < this->rowSize; i++){
    delete[] this->Matrix[i];
  }
  delete[] this->Matrix;
}

int** Matrix::genMatrix(int rowSize, int colSize){
  int ** tempMat = new int*[rowSize];

  for (int i = 0; i < rowSize; ++i){
    tempMat[i] = new int[colSize];
  }

  return temp;
}

void Matrix::print(){
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < cols; ++j){
      std::cout << this->mat[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Matrix::tran(){
  int** tempMat = genMatrix(this->colSize, this->rowSize);

  for (int i = 0; i < this -> colSize; ++i){
    for (int j = 0; i < this -> rowSize; ++j){
      tempMat[i][j] = this -> mat[i][j];
    }
  }
  for (int i = 0; i < this -> rowSize; ++i){
    delete[] this -> mat[i];
  }
  delete[] this -> mat;
  this -> mat = tempMat;
  int temp = this -> colSize;
  this -> rowSize = this -> colSize;
  this -> colSize = temp;
}

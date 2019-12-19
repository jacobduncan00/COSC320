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
    for (int j = 0; i < this -> rows; ++j){
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

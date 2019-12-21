#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
private:
  int rows= 0;
  int cols = 0;
  int** mat;

public:
  Matrix(int rows, int cols) : rows(rows), cols(cols) { 
    this -> mat = genMatrix(this -> rows, this -> cols);
  }
  ~Matrix();
  int** genMatrix(int rowSize, int cols);
  void populateMatrix(int* src, int size);
  void printMatrix();
  void tran();
  void add(Matrix& m);
  void sub(Matrix & m);
  void mult(Matrix& m);
  void div(Matrix& m);

  int getValueAt(int i, int j);
  int getNumRows();
  int getNumCols();
};

#include "matrix.cpp"

#endif

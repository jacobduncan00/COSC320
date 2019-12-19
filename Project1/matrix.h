#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
private:
  int rowSize = 0;
  int colSize = 0;
  int** mat;

public:
  Matrix(int rowSize, int colSize) : rowSize(rowSize), colSize(colSize) { }
  ~Matrix();
  int** genMatrix(int rowSize, colSize);
  void populateMatrix(int* src, int size);
  void printMatrix();
  void tran();
  void add(Matrix& m);
  void sub(Matrix & m);
  void mult(Matrix& m);
  void div(Matrix& m);
  int getValueAt(int i, int j);
};

#endif

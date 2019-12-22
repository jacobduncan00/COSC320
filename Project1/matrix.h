#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
private:
  int rows = 0;
  int cols = 0;
  float** mat;

public:
  Matrix(int rows, int cols) : rows(rows), cols(cols) {
    this -> mat = genMatrix(this -> rows, this -> cols);
  }
  ~Matrix();
  float** genMatrix(int rows, int cols);
  void populateMatrix(std::vector<float>&, int size);
  void printMatrix();
  void tran();
  void add(Matrix& m);
  void sub(Matrix & m);
  void mult(Matrix& m);
  void scalarMult(Matrix& m, int k);
  void div(Matrix& m);
  void inverse(Matrix& m);

  int getValueAt(int i, int j);
  int getNumRows();
  int getNumCols();
};

#include "matrix.cpp"

#endif

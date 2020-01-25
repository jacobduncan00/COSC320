#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix{
private:
  unsigned long int rows = 0;
  unsigned long int cols = 0;
  float** mat;

public:
  Matrix();
  Matrix(unsigned long int, unsigned long int);
  Matrix(const Matrix&);
  ~Matrix();
  void insert(int, int, float);
  float GetVal(int,int);
  void Determinant();
  Matrix& inverse();
  void TwoDRegression(std::string);
  void ThreeDRegression(std::string);
  void identityMatrix();
  void diagonalMatrix();
  void triangularMatrix(bool);
  void operator= (const Matrix&);
  friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix);
	friend Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb);
	friend Matrix operator- (const Matrix& matrixa, const Matrix& matrixb);
	friend Matrix operator* (const Matrix& matrixa, const Matrix& matrixb);
	friend Matrix operator* (const float& c, const Matrix& matrixa);
	friend Matrix operator^ (const Matrix& m, const char& exp);
};

#endif

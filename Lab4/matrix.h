#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix{
    private:
        long unsigned int** mat;
        long unsigned int rows;
        long unsigned int cols;
    public:
        Matrix();
        Matrix(long unsigned int, long unsigned int);
        Matrix(const Matrix&);
        ~Matrix();
        void identityMatrix();
        void diagonalMatrix();
        void triangularMatrix(bool);
        void printMatrix();
        void operator= (const Matrix&);
        friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix);
        friend Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator- (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator* (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator* (const long unsigned int& c, const Matrix& matrixa);
        friend Matrix operator^ (const Matrix& m, const char& exp);
};

//#include "matrix.cpp"

#endif
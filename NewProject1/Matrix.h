#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix{
    private:
        double** mat;
        long int rows;
        long int cols;
    public:
        Matrix();
        Matrix(long int, long int);
        Matrix(const Matrix&);
        ~Matrix();
        Matrix fillMatrix();
        void insert(long int, long int, double);
        double getVal(int, int);
        void determinant();
        Matrix transpose();
        Matrix& padMatrix();
        Matrix inverse();
        void twoDRegression(std::string); // takes in fileName by argv in main
        void identityMatrix();
        void diagonalMatrix();
        void triangularMatrix(bool);
        void printMatrix();
        void operator= (const Matrix&);
        friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix);
        friend Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator- (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator* (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator* (const Matrix& matrixa, const double& c);
        friend Matrix operator^ (const Matrix& m, const char& exp);
};

#endif
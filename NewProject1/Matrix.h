#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix{
    private:
        float** mat;
        unsigned long int rows;
        unsigned long int cols;
    public:
        Matrix();
        Matrix(unsigned long int, unsigned long int);
        Matrix(const Matrix&);
        ~Matrix();
        void fillMatrix(float);
        void insert(int, int, float);
        float getVal(int, int);
        void determinant();
        Matrix transpose();
        Matrix& padMatrix();
        Matrix& inverse();
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
        friend Matrix operator* (const float& c, const Matrix& matrixa);
        friend Matrix operator^ (const Matrix& m, const char& exp);
};

#endif
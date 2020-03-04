#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix{
    private:
        double** mat;
        long int rows;
        long int cols;
    public:
        Matrix(); // works
        Matrix(long int, long int); // work
        Matrix(const Matrix&); // works
        ~Matrix(); 
        Matrix fillMatrix(); // works
        void insert(long int, long int, double);
        double getVal(int, int);
        void determinant();
        bool isSymmetric();
        Matrix transpose();
        Matrix padMatrix(int);
        Matrix inverse();
        void twoDRegression(std::string); // takes in fileName by argv in main
        void identityMatrix(); // works
        void diagonalMatrix(); // works
        void triangularMatrix(bool); // works
        void printMatrix(); // works
        Matrix& operator= (const Matrix&); // works
        friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix);
        friend Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator- (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator* (const Matrix& matrixa, const Matrix& matrixb);
        friend Matrix operator* (const Matrix& matrixa, const double& c);
};

#endif
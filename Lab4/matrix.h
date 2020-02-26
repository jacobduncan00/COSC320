#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix{
    private:
        long int** mat; // main "Matrix" 2D Array
        long unsigned int rows; // Rows in the Array
        long unsigned int cols; // Cols in the Array
    public:
        Matrix(); // Default Constructor
        Matrix(long unsigned int, long unsigned int); // Constructor that takes parameters
        Matrix(const Matrix&); // Copy Constructor
        ~Matrix(); // Destructor
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
};

#endif

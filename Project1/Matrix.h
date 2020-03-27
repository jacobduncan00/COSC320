#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>

class Matrix{
    private:
        // 2D Array
        double** mat;
        // # of Rows in Matrix / Array
        long int rows;
        // # of Cols in Matrix / Array
        long int cols;
    public:
        // Default Constructor
        Matrix();
        // Overloaded Constructor takes Rows & Cols
        Matrix(long int, long int);
        // Copy Constructor
        Matrix(const Matrix&);
        // Destructor
        ~Matrix();
        // Overloaded Assignment Operator
        Matrix& operator= (const Matrix&);

        // Fill Matrix Test #1         used in driver
        Matrix fillMatrix();
        // Fill Matrix Test #2        used in driver   for testing
        Matrix fillMatrix2();
        // Fill Matrix Test #3        used in driver
        Matrix fillMatrix3();
        // inserts a double into the matrix at a specified location
        void insertNum(int, int, double);
        // returns a double in the matrix at a specified location
        double getVal(int, int);
        // finds determinant of a Matrix for extra credit
        void determinant();
        // Checks to see if Matrix is symmetrical
        bool isSymmetric();
        // Returns a tranposed Matrix of the one called upon
        Matrix transpose();
        // Pads the Matrix called upon to be a 2^N x 2^N
        Matrix padMatrix(int);
        // Returns the inverse of a given Matrix
        Matrix inverse();
        // Returns the Identity Matrix of a given Matrix
        void identityMatrix();
        // Creates the Diagonal Matrix of a given Matrix
        void diagonalMatrix();
        // Creates the Triangular Matrix of a given Matrix
        void triangularMatrix(bool);
        // Due to floating point errors, print that rounds the product of A * A inverse
        void inversePrint();
        // Prints out a Matrix
        void printMatrix();
        // Prints out the arithmetic counter for certain algorithms
        int printCounter();

        // Overloaded output operator, used to print Matrices
        friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix);
        // Overloaded addition operator, used to add Matrices
        friend Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb);
        // Overloaded subtraction operator, used to subtract Matrices
        friend Matrix operator- (const Matrix& matrixa, const Matrix& matrixb);
        // Overloaded multiplication operator, used to multiply Matrices
        friend Matrix operator* (const Matrix& matrixa, const Matrix& matrixb);
        // Overloaded multiplication operator, used to multiply matrices by a scalar
        friend Matrix operator* (const Matrix& matrixa, const double& c);
};

#endif

#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>

class Matrix{
    private:
        double** mat; // 2D Array
        long int rows; // # of Rows in Matrix / Array
        long int cols; // # of Cols in Matrix / Array
    public:
        Matrix(); // Default Constructor
        Matrix(long int, long int); // Overloaded Constructor takes Rows & Cols
        Matrix(const Matrix&); // Copy Constructor
        ~Matrix(); // Destructor
        Matrix& operator= (const Matrix&); // Overloaded Assignment Operator
        
        Matrix fillMatrix(); // Fill Matrix Test #1         used in driver
        Matrix fillMatrix2(); // Fill Matrix Test #2        used in driver   for testing
        Matrix fillMatrix3(); // Fill Matrix Test #3        used in driver
        void insertNum(int, int, double); // inserts a double into the matrix at a specified location
        double getVal(int, int); // returns a double in the matrix at a specified location
        bool isSymmetric(); // Checks to see if Matrix is symmetrical
        Matrix transpose(); // Returns a tranposed Matrix of the one called upon
        Matrix padMatrix(int); // Pads the Matrix called upon to be a 2^n x 2^n
        Matrix inverse(); // Returns the inverse of a given Matrix
        void identityMatrix(); // Returns the Identity Matrix of a given Matrix
        void diagonalMatrix(); // Creates the Diagonal Matrix of a given Matrix
        void triangularMatrix(bool); // Creates the Triangular Matrix of a given Matrix
        void inversePrint(); // Due to floating point errors, print that rounds the product of A * A inverse 
        void printMatrix(); // Prints out a Matrix
        int printCounter(); // Prints out the arithmetic counter for certain algorithms
        
        friend std::ostream& operator<< (std::ostream& os, const Matrix& matrix); // Overloaded output operator, used to print Matrices
        friend Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb); // Overloaded addition operator, used to add Matrices
        friend Matrix operator- (const Matrix& matrixa, const Matrix& matrixb); // Overloaded subtraction operator, used to subtract Matrices
        friend Matrix operator* (const Matrix& matrixa, const Matrix& matrixb); // Overloaded multiplication operator, used to multiply Matrices
        friend Matrix operator* (const Matrix& matrixa, const double& c); // Overloaded multiplication operator, used to multiply matrices by a scalar
};

#endif
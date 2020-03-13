#include <iostream>
#include <iomanip>
#include <math.h>
#include "Matrix.h"

// keeps track of arithmetic operations
namespace counter{ 
    int count = 0;
}

// default constructor forms a new 2D Array "Matrix" 3x3 

Matrix::Matrix(){ 
    mat = new double*[3];
    for(int i = 0; i < 3; i++){
      mat[i] = new double[3];
    }
    rows = 3;
    cols = 3;
}

// Overloaded constructor that takes in "rows" and "cols" long integer arguments
// This constructor will form a matrix given the parameters pass into it
// Ex. Matrix(4,5) makes a 4x5 Matrix

Matrix::Matrix(long int row, long int col){
  if (row <= 0 || col <= 0){
    throw "Invalid Matrix Size";
  } 
  rows = row;
  cols = col;
  mat = new double*[rows];
  for(long int i = 0; i < rows; i++){
    mat[i] = new double[cols];
  }
}

// Copy Constructor that takes in a constant Matrix by and assigns into 
// to a new Matrix that will be returned from the function
// Ex. Matrix b(Matrix a), therefore Matrix b would have the same contents
// as Matrix a

Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  // initializes rows of Matrix
  double** arr = new double*[rows];
  for(long int i = 0; i < rows; i++){
    // for every row in a Matrix make a column
    arr[i] = new double[cols];
  }
  mat = arr;
  for(long int i = 0; i < m.rows; i++){
    for(long int j = 0; j < cols; j++){
      // fills array with contents from the rhs Matrix
      mat[i][j] = m.mat[i][j];
    }
  }
}

// Destructor, deallocates the memory assigned by Matrix objects
// or functions that use the new operator to allocate memory

Matrix::~Matrix(){
  for(long int i = 0; i < this->rows; i++){
    // deletes every individual index in array
    delete[] mat[i];
  }
  // deletes the entire array
  delete[] mat;
}

// Function that fills a 3x3 Matrix with specific values
// shown below

Matrix Matrix::fillMatrix(){
    // creates a Matrix and fills it with preset numbers 
  Matrix A = Matrix(rows, cols);
  A.mat[0][0] = 8.0;
	A.mat[0][1] = 3.0;
	A.mat[0][2] = 8.0;
	A.mat[1][0] = 4.0;
	A.mat[1][1] = 9.0;
	A.mat[1][2] = 5.0;
	A.mat[2][0] = 7.0;
	A.mat[2][1] = 4.0;
	A.mat[2][2] = 7.0;
  return A;
}

// Function that fills a 3x3 Matrix with specific values
// shown below

Matrix Matrix::fillMatrix2(){
    // creates a Matrix and fills it with preset numbers
  Matrix A = Matrix(rows, cols);
  A.mat[0][0] = 5.0;
	A.mat[0][1] = 2.0;
	A.mat[0][2] = 3.0;
	A.mat[1][0] = 2.0;
	A.mat[1][1] = 6.0;
	A.mat[1][2] = 2.0;
	A.mat[2][0] = 3.0;
	A.mat[2][1] = 2.0;
	A.mat[2][2] = 6.0;
  return A;
}

// Function that fills a 4x4 Matrix with specific values
// shown below

Matrix Matrix::fillMatrix3(){
  // creates a Matrix and fills it with preset numbers
  Matrix A = Matrix(rows, cols);
  A.mat[0][0] = 5.0;
  A.mat[0][1] = 2.0;
  A.mat[0][2] = 3.0;
  A.mat[0][3] = 9.0;
  A.mat[1][0] = 2.0;
  A.mat[1][1] = 6.0;
  A.mat[1][2] = 2.0;
  A.mat[1][3] = 8.0;
  A.mat[2][0] = 3.0;
  A.mat[2][1] = 2.0;
  A.mat[2][2] = 6.0;
  A.mat[2][3] = 5.0;
  A.mat[3][0] = 9.0;
  A.mat[3][1] = 5.0;
  A.mat[3][2] = 7.0;
  A.mat[3][3] = 3.0;
  return A;
}

// Function that overwrites an index in the 2D array/matrix
// Ex Matrix a;
// a.insert(0,0,1) replaces the index [0][0] with the number 1=

void Matrix::insertNum(int i, int j, double num){
  if((i < 0 || i > this->rows) || (j < 0 || j > this->cols)){
    throw "ERROR: Indeces are not valid.";
  }
  this->mat[i][j] = num;
}

// Function that retreives the value in the 2D array/matrix
// Ex Matrix a;
// a.getVal(0,0) returns the number at index [0][0]

double Matrix::getVal(int i, int j){
  if((i < 0 || i > this->rows) || (j < 0 || j > this->cols)){
    throw "ERROR: Indeces are not valid.";
  }
  return this->mat[i][j];
}

// Function that calculates the determinant of Matrix 
// testing whether it is invertible or not "for extra credit"

void Matrix::determinant(){
	int det = 0;
	if(rows != cols){
	  std::cout << "Matrix is not square, cannot be invertible" << std::endl;
  }
	if(rows == 2 && cols == 2){
		det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
		if(det == 0){
			std::cout << "Matrix is not invertible" << std::endl;
    }
		else{
			std::cout << "Matrix is invertible" << std::endl;
    }
	} else if (rows == 3 && cols == 3){
		  det = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0]
			    + mat[0][2] * mat[1][0] * mat[2][1] - (mat[0][2] * mat[1][1] * mat[2][0]
			    +  mat[0][0] * mat[1][2] * mat[2][1] +  mat[0][1] * mat[1][0] * mat[2][2]);
		if(det == 0){
			std::cout << "Matrix is not invertible" << std::endl;
    }
		else{
			std::cout << "Matrix is invertible" << std::endl;
    }
	} else {
		int count = 0;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				det += mat[i][j];
				
			}
			if(det == 0)
				std::cout << "Matrix is not invertible" << std::endl;
			else
				count++;
		}
		if(count == rows -1)
			std::cout << "Matrix is invertible" << std::endl;
	}
}

// Function that checks whether a Matrix is symmetrical or not
// Meaning whether the values reflected across the main diagonal
// are the same or not.
// Ex. Matrix A = [1 2 3 
//                 2 4 5
//                 3 5 8] is symmetric
// 
// where as Matrix B = [1 2 3
//                      4 5 6
//                      7 8 9] is not symmetric

bool Matrix::isSymmetric(){
  Matrix a = *this;
  Matrix b = this->transpose();
  for(long int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      // if the original is not the same as the tranpose, shows symmetry
      if(a.mat[i][j] != b.mat[i][j]){ 
        return false;
      }
    }
  }
  return true;
}

// Function that creates a new Matrix which is the transpose of 
// the Matrix that called the function.
// Ex. Matrix A = [1 2 3
//                 4 5 6
//                 7 8 9];
// A.transpose();
// A now looks like [1 4 7 
//                   2 5 8 
//                   3 6 9];

Matrix Matrix::transpose(){ 
	Matrix transpose(cols, rows);
	for(long int i = 0; i < rows; i++){
		for(long int j = 0; j < cols; j++){
			transpose.mat[j][i] = mat[i][j];
    }
  }
  counter::count++;
  return transpose;
}

// Function that pads a Matrix to become a 2^N x 2^N
// For example Matrix A = [1 2 3
//                         4 5 6
//                         7 8 9] needs to be padded to     |
//                                                          V
//
//                                                       [1 2 3 0
//                                                        4 5 6 0
//                                                        7 8 9 0 
//                                                        0 0 0 0] in order to use inverse function 

Matrix Matrix::padMatrix(int d){
  int size = 0;
  // finds the next highest 2^N value "power of 2"
  while(log2(d + size) - (int)log2(d + size) != 0){ 
    size++;
  }
  // creates new Matrix with the new padded size
  Matrix rtn(d+size, d+size); 
  Matrix id(size, size);
  id.identityMatrix();
  for(long int i = 0; i < rtn.rows; i++){
    for(long int j = 0; j < rtn.cols; j++){
      if(i < d && j < d){
        rtn.mat[i][j] = mat[i][j];
      }
      if(i >= d && j >= d){
        rtn.mat[i][j] = id.mat[i-d][j-d];
      }
      if((i >= d && j < d) || (i < d && j >= d)){
        rtn.mat[i][j] = 0;
      }
    }
  }
  return rtn;
}

Matrix Matrix::inverse(){
  // if not a square Matrix
  if(rows != cols){ 
    throw "Not a square matrix!";
  }

  // if Matrix is a 1x1
  if(rows == 1 || cols == 1){ 
    Matrix rtn(1,1);
    if(mat[0][0] != 0){
      rtn.mat[0][0] = 1.0/mat[0][0];
    }
    else{
      rtn.mat[0][0] = 0;
    }
    return rtn;
  }

  int holdRows = rows;
  // checks to see if Matrix is a 2^Nx2^N "a power of 2"
  if(log2(rows) - (int)log2(rows) != 0){ 
    Matrix temp = padMatrix(rows);
    Matrix curr = temp.inverse();
    Matrix rtn(holdRows, holdRows);
    for(long int i = 0; i < holdRows; i++){
      for(long int j = 0; j < holdRows; j++){
        rtn.mat[i][j] = curr.mat[i][j];
      }
    }
    return rtn;
  }

  // checks to see if the Matrix is symmetric
  if(!isSymmetric()){ 
    // Takes another Matrix to hold the current one
    Matrix op1 = *this; 
    // transposes Matrix
    Matrix op2 = op1.transpose();
    // multiplies Matrix by it's transpose
    Matrix op3 = op2 * op1; 
    // inverses that entire operation and multiplies by it's tranpose once again
    Matrix op4 = op3.inverse() * op2; 

    return op4;
  }

	long int row2 = rows/2;
	long int col2 = cols/2;

	Matrix B(row2, col2); // n/2 matrix
	Matrix C(row2, col2); // n/2 matrix           Splitting Matrix into 4 slices
	Matrix CT(row2, col2); // n/2 matrix
	Matrix D(row2, col2); // n/2 matrix

	for(long int i = 0; i < rows; i++){
		for(long int j = 0; j < cols; j++){
			if(i < row2 && j < col2){ //top left
				B.mat[i][j] = mat[i][j];
      }
			if(i < row2 && j >= col2){ //top right
				CT.mat[i][j - col2] = mat[i][j];
      }
			if(i >= row2 && j < col2){ // bottom left
				C.mat[i - row2][j] = mat[i][j];
      }
			if(i >= row2 && j >= col2){ //bottom right
				D.mat[i - row2][j - col2] = mat[i][j];
      }

		}
  }

	Matrix BI = (B.inverse()); // recursively calls this function
	Matrix W = (C) * (BI);
  Matrix WT = W.transpose();
	Matrix X = W * CT;
	Matrix S = D - X;
	Matrix V = (S.inverse()); // recursively calls this function
	Matrix Y = V * (W);
	Matrix YT = Y.transpose();
	Matrix T = (YT * -1);
	Matrix U = (Y * -1);
	Matrix Z = (WT) * (Y);
	Matrix R = BI + Z;

  Matrix rtnNew(rows, cols);

  for(long int i = 0; i < rows; i++){
		for(long int j = 0; j < cols; j++){
			if(i < row2 && j < col2){ //top left
				rtnNew.mat[i][j] = R.mat[i][j];
      }
			if(i < row2 && j >= col2){ //top right
				rtnNew.mat[i][j] = T.mat[i][j-col2];
      }
			if(i >= row2 && j < col2){ // bottom left
				rtnNew.mat[i][j] = U.mat[i-row2][j];
      }
			if(i >= row2 && j >= col2){ //bottom right
				rtnNew.mat[i][j] = V.mat[i-row2][j-col2];
      }
		}
  }
	return rtnNew;
}

// Function that turns a Matrix into it's respected identity Matrix
// given its dimensions

void Matrix::identityMatrix(){
  Matrix temp(this->rows, this->cols);
  for(long int i = 0; i < this->rows; i++){
    for(long int j = 0; j < this->cols; j++){
      if(i == j){
        mat[i][j] = 1; // creates 1's down the main diagonal
      }
      else{
        mat[i][j] = 0; // everywhere else is 0's
      }
    }
  }
}

// Function that turns a Matrix into it's respected diagonal Matrix
// given its dimensions

void Matrix::diagonalMatrix(){
  for(long int i = 0; i < this->rows; i++){
    // 9 for visual purposes
    this->mat[i][i] = 9;
  }
}

// Function that turns a Matrix into it's respected triangular Matrix
// given its dimensions. Takes in a boolean value as a parameter and
// this determines whether or not it will be a upper or lower triangle
// if boolean value passed in is true it will be a upper triangle where as if
// the boolean value passed in is false it will be a lower triangle

void Matrix::triangularMatrix(bool up){
  if(up){
    for(long int i = 0; i < this->rows; i++){
      for(long int j = 0; j < this->rows; j++){
        if(i < j){
          // 9 for visual purposes
          // creates 9's in the upper quadrant of the triangle
          this->mat[i][j] = 9;
        }
        else{
          // else put 0's in the lower quadrant of the triangle
          this->mat[i][j] = 0; 
        }
      }
    }
  }
  else{
    for(long int i = 0; i < this->rows; i++){
      for(long int j = 0; j < this->rows; j++){
        if(i > j){
          // 9 for visual purposes
          // creates 9's in the lower quadrant of the triangle
          this->mat[i][j] = 9; 
        }
        else{
          // else put 0's in the upper quadrant of the triangle
          this->mat[i][j] = 0; 
        }
      }
    }
  }
}

// Function that addresses the floating point rounding error in C++
// This function will round numbers between 0.9 ~ 1 to 1
// and will round numbers between -.1 ~ 0 to 0
// I do this because this will truly show that A * A.inverse() is indeed the 
// identity Matrix

void Matrix::inversePrint(){ 
  for(long int i = 0; i < this->rows; i++){
        if(i != 0){
            std::cout << std::endl;
	      }
        for(long int j = 0; j < this->cols; j++){
          if(this->mat[i][j] > 0.9 && this->mat[i][j] < 1){
            std::cout << std::setw(5) << 1 << " ";;
          }
          else if(this->mat[i][j] > -.1 && this->mat[i][j] < 0){
            std::cout << std::setw(5) << 0 << " ";
          }
          else{
            std::cout << std::setw(5) << (int)this->mat[i][j] << " ";
          }
        }
  }
    std::cout << std::endl;
    std::cout << std::endl;
}

// Function that prints out a Matrix normally
// Essentially printing a 2D array

void Matrix::printMatrix(){
    for(long int i = 0; i < this->rows; i++){
        if(i != 0){
          std::cout << std::endl;
        }
        for(long int j = 0; j < this->cols; j++){
          std::cout << std::setw(5) << this->mat[i][j] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

// For any given Matrix, this function will print 
// the number of arithmetical operations that Matrix
// had applied to itself

int Matrix::printCounter(){
  return counter::count;
}

// Overloaded assignment operator used for assigning
// Matrices to other Matrices
// Ex. Matrix A (5,5);
// Matrix B (5,5);
// B = A;

Matrix& Matrix::operator=(const Matrix& m){
  // when matrices are already the same
  if(this == &m){ 
    return *this; 
  }
  // else delete old
  for(long int i = 0; i < rows; i++){
    delete[] mat[i];
  }
  delete[] mat;
  // create new
  mat = new double*[m.rows];
  for(long int i = 0; i < m.rows; i++){
    mat[i] = new double[m.cols];
  }

  // assign rows and cols from previous
  rows = m.rows;
  cols = m.cols;

  // copy over content
  for(long int i = 0; i < rows; i++){
    for(long int j = 0; j < cols; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
  counter::count++;
  return *this;
}

// Overloaded outstream operator that is used to print Matrices easier
// Ex. Matrix A (5,5);
// std::cout << A << std::endl;
// Will print the content of the Matrix the same way A.printMatrix()
// would

std::ostream& operator<< (std::ostream& os, const Matrix& matrix){
    for(long int i = 0; i < matrix.rows; i++){
        for(long int k = 0; k < matrix.cols; k++){
            os << matrix.mat[i][k] << " ";
        }
        std::cout << std::endl;
    }
    return os;
}

// Overloaded addition operator that is used to add Matrices together
// Ex. Matrix A (5,5);
// Matrix B (5,5);
// Matrix C = A + B;

Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows != matrixb.rows || matrixa.cols != matrixb.cols){
		throw "Invalid matrix size combination.";
	}

	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(long int i = 0; i < matrixa.rows; i++){
		for(long int k = 0; k < matrixa.cols; k++){
			matrixc.mat[i][k] = matrixa.mat[i][k] + matrixb.mat[i][k];
    }
  }
  counter::count++;
	return matrixc;
}

// Overloaded subtraction operator that is used to subtract Matrices
// Ex. Matrix A (5,5);
// Matrix B (5,5);
// Matrix C = A - B;

Matrix operator- (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows!= matrixb.rows|| matrixa.cols != matrixb.cols){
		throw "Invalid matrix size combination.";
	}
	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(long int i = 0; i < matrixa.rows;i++){
		for(long int k = 0; k < matrixa.cols; k++){
			matrixc.mat[i][k] = matrixa.mat[i][k] - matrixb.mat[i][k];
    }
  }
  counter::count++;
	return matrixc;
}

// Overloaded multiplication operator that is used to multiply Matrices together
// Ex. Matrix A (5,5);
// Matrix B (5,5);
// Matrix C = A * B;


Matrix operator* (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.cols != matrixb.rows){
	  throw "Invalid matrix size combination.";
	}
	Matrix matrixc(matrixa.rows, matrixb.cols);
	for(long int i = 0; i < matrixa.rows; i++){
		for(long int j = 0; j < matrixb.cols; j++){
      double sum = 0.0;
      for(long int l = 0; l < matrixa.cols; l++){
        sum += matrixa.mat[i][l] * matrixb.mat[l][j];
      }
      matrixc.mat[i][j] = sum;
    }
  }
  counter::count++;
	return matrixc;
}

// Overloaded addition operator that is used to multiply Matrices by a scalar
// Ex. Matrix A (5,5);
// double B = 5;
// Matrix C = A * B; or Matrix C = A * 5;

Matrix operator* (const Matrix& matrixa, const double& c){ 
	Matrix matrixb(matrixa.rows, matrixa.cols);
	for(long int i = 0; i < matrixa.rows; i++){
		for(long int k = 0; k < matrixa.cols; k++){
			matrixb.mat[i][k] = (matrixa.mat[i][k] * c);
    }
  }
  counter::count++;
	return matrixb;
}

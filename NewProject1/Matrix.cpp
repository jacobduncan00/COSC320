#include <iostream>
#include <iomanip>
#include <math.h>
#include "Matrix.h"

#define RESET "\033[0m"
#define WHITE "\033[37m" 
#define PURPLE "\033[35m"
#define RED "\033[31m" 

namespace counter{
    int count = 0;
}

Matrix::Matrix() : rows(1), cols(1) {
    mat = new float*[rows];
    for(int i = 0; i < rows; i++){
        mat[i] = new float[cols];
    }
    mat[0][0] = 0;
}

Matrix::Matrix(unsigned long int row, unsigned long int col){
  if (row < 1 || col < 1){
    std::cout << "Invalid Matrix Size" << std::endl;
    exit(1);
  } 
  rows = row;
  cols = col;
  mat = new float*[row];
  srand(time(NULL));
    for(int i = 0; i < rows; i++){
      mat[i] = new float[cols];
      for (int j = 0; j < cols; j++){
        mat[i][j] = 0; // could be rows too 
      }
    }
}


Matrix::Matrix(const Matrix& m){
  rows = m.rows;
  cols = m.cols;
  float** arr = new float*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new float[cols];
  }
  mat = arr;
  for(int i = 0; i < m.rows; i++){
    for(int j = 0; j < cols; j++){
      mat[i][j] = m.mat[i][j];
    }
  }
}

Matrix::~Matrix(){
  for(int i = 0; i < this -> rows; i++){
    delete[] this -> mat[i];
  }
  delete[] this -> mat;
}

void Matrix::insert(int i, int j, float num){
  mat[i][j] = num;
}

float Matrix::getVal(int i, int j){
  return mat[i][j];
}

void Matrix::determinant(){
  int det = 0;
  if(rows != cols){
    std::cout << "Matrix is not a square, cannot be invertible" << std::endl;
  }
  if(rows == 2 && cols == 2){
    det = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
  }
  else if (rows == 3 && cols == 3){
    det = (mat[0][0] * mat[1][1] * mat[2][2]
			  + mat[0][1]  * mat[1][2] * mat[2][0]
		  	+ mat[0][2]  * mat[1][0] * mat[2][1])
		  	- (mat[0][2] * mat[1][1] * mat[2][0]
		  	+  mat[0][0] * mat[1][2] * mat[2][1]
		  	+  mat[0][1] * mat[1][0] * mat[2][2]);
  }
  else{
    for(int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        det+=mat[i][j];
      }
    }
  }
}

Matrix& Matrix::padMatrix(){
	//check if needs to be padded
	int size = 2;
	while((size < rows || size < cols) && size > 0 ){
		size = size * 2; 
	} //no remainder
	float** old = mat;
	int prevRows = rows;
	int prevCol = cols;
	

	//size is now rows and columns
	rows = cols = size;
	mat = new float*[rows];
	for(int i = 0; i < rows; i++){
		mat[i] = new float[cols];
		//set all elements to 0
		for(int j = 0; j < cols; j++){
			mat[i][j] = 0;
		}
	};

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){

			if(i >= prevRows || j >= prevCol){
				if(i == j){
					mat[i][j] = 1;
				}else{
					mat[i][j] = 0;
				}//end of inside
			}else{
				mat[i][j] = old[i][j];
			}
		}
	} //end for 
	
	for(int i = 0; i < prevRows; i++){
		delete [] old[i];
	}
	delete [] old;

	return *this;

};

Matrix Matrix::transpose(){
	Matrix transposed = Matrix(cols, rows);
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			transposed.mat[j][i] = mat[i][j];
		}
	}
	return transposed;
};

Matrix& Matrix::inverse(){
	// Please use a 2^n x 2^n matrix.
  // Assuming that "this" is a square (n x n) matrix and is symmetric
	//int row = this->rows;
  int row = rows;
  std::cout << "Rows: " << row << std::endl;
	//int col = this->cols;
  int col = cols;
  std::cout << "Cols: " << col << std::endl;
	int row2 = row/2;
  std::cout << "Rows/2: " << row2 << std::endl;
	int col2 = col/2;
  std::cout << "Cols/2: " << col2 << std::endl;

	if(row == 1 && col == 1){ // base case where the Matrix is a 1x1
			if(mat[0][0] != 0){ // Cannot divide by 0.
				mat[0][0] = (1.0 / mat[0][0]);
      }
			return *this;
	}

	Matrix B(row2, col2); // n/2 matrix
  std::cout << "Matrix B: " << std::endl;
  std::cout << std::endl;
  std::cout << B;
  std::cout << std::endl;
	Matrix C(row2, col2); // n/2 matrix
  std::cout << "Matrix C: " << std::endl;
  std::cout << std::endl;
  std::cout << C;
  std::cout << std::endl;
	Matrix D(row2, col2); // n/2 matrix
  std::cout << "Matrix D: " << std::endl;
  std::cout << std::endl;
  std::cout << D;
  std::cout << std::endl;
	Matrix CT = C^'T'; // C transpose
  std::cout << "Matrix C transpose: " << std::endl;
  std::cout << std::endl;
  std::cout << CT;

	for(int i = 0; i < row2; i++){
		for(int j = 0; j < col2; j++){
			B.mat[i][j] = mat[i][j];
    }
  }

	for(int i = 0; i < row2; i++){
		for(int j = (col2); j < col; j++){
			CT.mat[i][j - col2] = mat[i][j];
    }
  }

	for(int i = (row2); i < row; i++){
		for(int j = 0; j < col2; j++){
			C.mat[i - row2][j] = mat[i][j];
    }
  }

	for(int i = (row2); i < row; i++){
		for(int j = (col2); j < col; j++){
	 		D.mat[i - row2][j - col2] = mat[i][j];
    }
  }

  std::cout << std::endl;
  std::cout << "AFTER FILLING" << std::endl;
  std::cout << std::endl; 
  std::cout << "Matrix B: " << std::endl;
  std::cout << std::endl;
  std::cout << B;
  std::cout << "Matrix C: " << std::endl;
  std::cout << std::endl;
  std::cout << C;
  std::cout << "Matrix D: " << std::endl;
  std::cout << std::endl;
  std::cout << D;
  std::cout << "Matrix C Transpose: " << std::endl;
  std::cout << std::endl;
  std::cout << CT;

	Matrix BI = (B.inverse()); // recursively call this function
  std::cout << std::endl;   
  std::cout << "B Inverse: " << std::endl;
  std::cout << BI; // should be 10
  std::cout << std::endl;

	Matrix W = (C) * (BI);
  std::cout << "W: " << std::endl;
  std::cout << W; 
  std::cout << std::endl;

  Matrix WT = BI * CT; // this gives 30
  Matrix WTrans = W.transpose();
	//Matrix WT = W^'T'; // this gives 6, same as W, so is it really transposing?
  std::cout << "W Transpose:" << std::endl;
  std::cout << WTrans;
  std::cout << std::endl;

	Matrix X = (W) * (CT);
  std::cout << "X: " << std::endl;
  std::cout << X;
  std::cout << std::endl;

	Matrix S = D - X;
  std::cout << "S" << std::endl;
  std::cout << S;
  std::cout << std::endl;

	Matrix V = (S.inverse());
  std::cout << "V: " << std::endl;
  std::cout << V;
  std::cout << std::endl;

	Matrix Y = V * (W);
  std::cout << "Y: " << std::endl;
  std::cout << Y;
  std::cout << std::endl;

	Matrix YT = Y^'T';
  std::cout << "YT: " << std::endl;
  std::cout << Y;
  std::cout << std::endl;

	Matrix T = (-1 * YT);
  std::cout << "T: " << std::endl;
  std::cout << T;
  std::cout << std::endl;

	Matrix U = (-1 * Y);
  std::cout << "U: " << std::endl;
  std::cout << U;
  std::cout << std::endl;

	Matrix Z = (WT) * (Y);
  std::cout << "Z: " << std::endl;
  std::cout << Z;
  std::cout << std::endl;
  
	Matrix R = BI + Z;
  std::cout << "R: " << std::endl;
  std::cout << R;
  std::cout << std::endl;

	for(int i = 0; i < row2; i ++)
		for(int j = 0; j < col2; j++)
			mat[i][j] = R.mat[i][j];


	for(int i = row2; i < row; i++)
		for(int j = 0; j < col2; j++)
			mat[i][j] = U.mat[i - row2][j];


	for(int i = 0; i < row2; i++)
		for(int j = col2; j < col; j++)
			mat[i][j] = T.mat[i][j - col2];


	for(int i = row2; i < row; i++)
		for(int j = col2; j < col; j++)
			mat[i][j] = V.mat[i - row2][j - col2];

	return *this;
}

void Matrix::twoDRegression(std::string fileName){
  std::ifstream infile(fileName);
  if(!infile.is_open()){
      	std::cout << "File Opening Error.\n";
      	exit (1);
  }
  int datasize;
  if(fileName == "points100.dat"){
    datasize = 100;
  }
  else if(fileName == "points500.dat"){
    datasize = 500;
  }
  else if(fileName == "points1000.dat"){
    datasize = 1000;
  }
  else if(fileName == "points5000.dat"){
    datasize = 5000;
  }
  else if(fileName == "points10000.dat"){
    datasize = 10000;
  }
  else if(fileName == "points50000.dat"){
    datasize = 50000;
  }
  else if(fileName == "points100000.dat"){
    datasize = 100000;
  }
  else{
    std::cout << "Data Size could not be calculated!" << std::endl;
    return;
  }
  float c1, c2;
  Matrix *A = new Matrix(datasize, 2);
  Matrix *b = new Matrix(datasize, 1);
  for(int i = 0; i < datasize; i++){
    infile >> c1;
    //std::cout << "1st Value: " << c1 << std::endl;
    infile >> c2;
    //std::cout << "2nd Value: " << c2 << std::endl;
    A->insert(i, 0, c1);
    b->insert(i, 0, c2);
    A->insert(i, 1, 1.0);
  }
  infile.close();
  Matrix AT = (*A)^'T';
  Matrix Beta = (((AT * *A).inverse() * AT) * *b);
  std::cout << "[2D] Aβ = [A]*[β]=[x] = b:" << std::endl;
  std::cout << Beta << std::endl; // Prints regression line.
}


void Matrix::identityMatrix(){
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = 1;
  }
}

void Matrix::diagonalMatrix(){
  srand(time(NULL));
  for(int i = 0; i < this->rows; i++){
    this->mat[i][i] = 999;
  }
}

void Matrix::triangularMatrix(bool up){
  srand(time(NULL));
  if(up){
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->rows; j++){
        if(i < j){
          this->mat[i][j] = 999;
        }
        else{
          this->mat[i][j] = 0;
        }
      }
    }
  }
  else{
    for(int i = 0; i < this->rows; i++){
      for(int j = 0; j < this->rows; j++){
        if(i > j){
          this->mat[i][j] = 999;
        }
        else{
          this->mat[i][j] = 0;
        }
      }
    }
  }
}

void Matrix::printMatrix(){
    for(int i = 0; i < this->rows; i++){
        if(i != 0)
            std::cout << std::endl;
        for(int j = 0; j < this->cols; j++){
              std::cout << std::setw(5) << this->mat[i][j] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void Matrix::operator=(const Matrix& m){
  Matrix copy(m);
  rows = m.rows;
  cols = m.cols;
  float** arr = new float*[rows];
  for(int i = 0; i < rows; i++){
    arr[i] = new float[cols];
  }
  mat = arr;
  float** temp = mat;
  mat = copy.mat;
  copy.mat = temp;
  counter::count++;
}

std::ostream& operator<< (std::ostream& os, const Matrix& matrix){
    for(int i = 0; i < matrix.rows; i++){
        for(int k = 0; k < matrix.cols; k++)
            os << matrix.mat[i][k] << " ";
        std::cout << "\n";
        }
        return os;
}

Matrix operator+ (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows != matrixb.rows || matrixa.cols != matrixb.cols){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}

	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixc.mat[i][k] = matrixa.mat[i][k] + matrixb.mat[i][k];
    counter::count++;
	return matrixc;
}

Matrix operator- (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.rows!= matrixb.rows|| matrixa.cols != matrixb.cols){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}

	Matrix matrixc(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows;i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixc.mat[i][k] = matrixa.mat[i][k] - matrixb.mat[i][k];
    counter::count++;
	return matrixc;
}

Matrix operator* (const Matrix& matrixa, const Matrix& matrixb){
	if(matrixa.cols != matrixb.rows){
		std::cout << "Invalid matrix size combination.";
		exit (1);
	}
	Matrix matrixc(matrixa.rows, matrixb.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixb.cols; k++)
			for(int p = 0; p < matrixb.rows; p++)
				matrixc.mat[i][k] += (matrixa.mat[i][p] * matrixb.mat[p][k]);

    counter::count++;
	return matrixc;
}

Matrix operator* (const float& c, const Matrix& matrixa){ // Scalar Mult.
	Matrix matrixb(matrixa.rows, matrixa.cols);
	for(int i = 0; i < matrixa.rows; i++)
		for(int k = 0; k < matrixa.cols; k++)
			matrixb.mat[i][k] = (matrixa.mat[i][k] * c);

    counter::count++;
	return matrixb;
}

Matrix operator^ (const Matrix& m, const char& exp){
	Matrix matrixb(m.cols, m.rows);
	for(int i = 0; i < m.rows; i++)
		for(int j = 0; j < m.cols; j++)
			matrixb.mat[j][i] = m.mat[i][j];

    counter::count++;
	return matrixb;
}
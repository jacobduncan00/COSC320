#include <iostream>
#include <chrono>
#include "matrix.h"

/*
    Lab 4 by Jacob Duncan at Salisbury Universtiy for Dr. Joseph Anderson
    COSC 320. This lab displays Matrix operations in C++. I demonstrated
    Matrix addition, multiplication, Diagonal, Triangular (Upper and Lower), 
    Identity, as well as Vector Matrices. I also included time trials 
    for multiplying different Matrices varying in size and form.
*/

int main(){
    long unsigned int arr[4] = {10,20,30,40};

    Matrix A (arr[0], arr[0]);
    std::cout << std::endl; 
    std::cout << "\e[1mMatrix A\e[0m" << std::endl;
    std::cout << std::endl;
    A.printMatrix();

    std::cout << "\e[1mMatrix B\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix B (arr[0], arr[0]);
    B.printMatrix();

    std::cout << "\e[1mMatrix A + Matrix B\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix C = A + B;
    C.printMatrix();

    std::cout << "\e[1mMatrix A - Matrix B\e[0m" << std::endl;
    std::cout << "\e[1mMatrix A = Matrix B, therefore should be all 0's\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix CC = A - B;
    CC.printMatrix();

    std::cout << "\e[1mMatrix A * Matrix B\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix D = A * B;
    D.printMatrix();

    std::cout << "\e[1mMatrix A * 5 (Scalar Mult)\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix DD = 5 * A; // make sure # first, then matrix
    DD.printMatrix();

    Matrix E;
    E.diagonalMatrix();
    std::cout << "\e[1mDiagonal Matrix\e[0m" << std::endl;
    std::cout << std::endl;
    E.printMatrix();

    Matrix F;
    F.triangularMatrix(true);
    std::cout << "\e[1mTriangular Matrix Upper\e[0m" << std::endl;
    std::cout << std::endl;
    F.printMatrix();

    Matrix G;
    G.triangularMatrix(false);
    std::cout << "\e[1mTriangular Matrix Lower\e[0m" << std::endl;
    std::cout << std::endl;
    G.printMatrix();

    Matrix H;
    H.identityMatrix();
    std::cout << "\e[1mIdentity Matrix\e[0m" << std::endl;
    std::cout << std::endl;
    H.printMatrix();
    std::cout << std::endl;

    Matrix I(1, 10);
    std::cout << "\e[1mVector Matrix\e[0m" << std::endl;
    std::cout << std::endl;
    I.printMatrix();

    std::cout << "\e[1mMultiplication Time\e[0m" << std::endl;
    std::cout << "\e[1m===================\e[0m" << std::endl;
    std::cout << std::endl;
    long unsigned int matrixSizes[6] = {500, 600, 700, 800, 900, 1000};
    for(int i = 0; i < 6; i++){ 
        Matrix *gen = new Matrix(matrixSizes[i], matrixSizes[i]);
        Matrix *gen2 = new Matrix(matrixSizes[i], matrixSizes[i]);
        std::cout << "Type: Random" << std::endl;
        std::cout << "Size: " << matrixSizes[i] << "x" << matrixSizes[i] << std::endl;
        auto timeStart = std::chrono::system_clock::now();
        Matrix gen3 = *gen * *gen2;
        auto timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed_time2 = timeEnd-timeStart;
        std::cout << "Time: " << elapsed_time2.count() << "s" << std::endl;
        std::cout << std::endl;
        delete gen;
        delete gen2;
    }
    std::cout << "\e[1m=============\e[0m" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 6; i++){
        Matrix *gen = new Matrix(matrixSizes[i], matrixSizes[i]);
        Matrix *gen2 = new Matrix(matrixSizes[i], matrixSizes[i]);
        gen->triangularMatrix(true); // upper 
        gen2->triangularMatrix(true); // upper
        std::cout << "Type: Upper Triangular" << std::endl;
        std::cout << "Size: " << matrixSizes[i] << "x" << matrixSizes[i] << std::endl;
        auto timeStart = std::chrono::system_clock::now();
        Matrix gen3 = *gen * *gen2;
        auto timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed_time2 = timeEnd-timeStart;
        std::cout << "Time: " << elapsed_time2.count() << "s" << std::endl;
        std::cout << std::endl;
        delete gen;
        delete gen2;
    }
    std::cout << "\e[1m=============\e[0m" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 6; i++){
        Matrix *gen = new Matrix(matrixSizes[i], matrixSizes[i]);
        Matrix *gen2 = new Matrix(matrixSizes[i], matrixSizes[i]);
        gen->triangularMatrix(false); // lower
        gen2->triangularMatrix(false); // lower
        std::cout << "Type: Lower Triangular" << std::endl;
        std::cout << "Size: " << matrixSizes[i] << "x" << matrixSizes[i] << std::endl;
        auto timeStart = std::chrono::system_clock::now();
        Matrix gen3 = *gen * *gen2;
        auto timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed_time2 = timeEnd-timeStart;
        std::cout << "Time: " << elapsed_time2.count() << "s" << std::endl;
        std::cout << std::endl;
        delete gen;
        delete gen2;
    }
    std::cout << "\e[1m=============\e[0m" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 6; i++){
        Matrix *gen = new Matrix(matrixSizes[i], matrixSizes[i]);
        Matrix *gen2 = new Matrix(matrixSizes[i], matrixSizes[i]);
        gen->identityMatrix(); 
        gen2->identityMatrix();
        std::cout << "Type: Identity" << std::endl;
        std::cout << "Size: " << matrixSizes[i] << "x" << matrixSizes[i] << std::endl;
        auto timeStart = std::chrono::system_clock::now();
        Matrix gen3 = *gen * *gen2;
        auto timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed_time2 = timeEnd-timeStart;
        std::cout << "Time: " << elapsed_time2.count() << "s" << std::endl;
        std::cout << std::endl;
        delete gen;
        delete gen2;
    }
    std::cout << "\e[1m=============\e[0m" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 6; i++){
        Matrix *gen = new Matrix(matrixSizes[i], matrixSizes[i]);
        Matrix *gen2 = new Matrix(matrixSizes[i], matrixSizes[i]);
        gen->diagonalMatrix();  
        gen2->diagonalMatrix(); 
        std::cout << "Type: Diagonal" << std::endl;
        std::cout << "Size: " << matrixSizes[i] << "x" << matrixSizes[i] << std::endl;
        auto timeStart = std::chrono::system_clock::now();
        Matrix gen3 = *gen * *gen2;
        auto timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed_time2 = timeEnd-timeStart;
        std::cout << "Time: " << elapsed_time2.count() << "s" << std::endl;
        std::cout << std::endl;
        delete gen;
        delete gen2;
    }
   
    return 0;
}
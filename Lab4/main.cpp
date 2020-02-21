#include <iostream>
#include <chrono>
#include "matrix.h"

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
    std::cout << "\e[1mMatrix A * Matrix B\e[0m" << std::endl;
    std::cout << std::endl;

    Matrix D = A * B;
    D.printMatrix();

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
    }
    std::cout << "\e[1m=============\e[0m" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 6; i++){
        Matrix *gen = new Matrix(matrixSizes[i], matrixSizes[i]);
        Matrix *gen2 = new Matrix(matrixSizes[i], matrixSizes[i]);
        gen->identityMatrix(); // upper 
        gen2->identityMatrix(); // upper
        std::cout << "Type: Identity" << std::endl;
        std::cout << "Size: " << matrixSizes[i] << "x" << matrixSizes[i] << std::endl;
        auto timeStart = std::chrono::system_clock::now();
        Matrix gen3 = *gen * *gen2;
        auto timeEnd = std::chrono::system_clock::now();
        std::chrono::duration<double>elapsed_time2 = timeEnd-timeStart;
        std::cout << "Time: " << elapsed_time2.count() << "s" << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
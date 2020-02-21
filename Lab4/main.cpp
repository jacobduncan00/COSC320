#include <iostream>
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
    std::cout << "\e[1mTriangular Matrix Upper\e[0m" << std::endl;
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
    return 0;
}
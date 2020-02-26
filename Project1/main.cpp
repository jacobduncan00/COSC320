#include <iostream>
#include "matrix.h"

int main(){
    Matrix A(2,2);
    Matrix B = A;
    Matrix C;
    Matrix D = A;
    std::cout << "Matrix A" << std::endl;
    A.printMatrix();
    std::cout << "Matrix A Inverse" << std::endl;
    B.inverse();
    B.printMatrix();
    std::cout << "A * A Inverse" << std::endl;
    C = A * A.inverse();
    C.printMatrix();
    std::cout << "A Identity Matrix" << std::endl;
    std::cout << std::endl;
    D.identityMatrix();
    D.printMatrix();
    return 0;
}

#include "matrix.h"
#include <iostream>

int main(){
    srand(time(NULL));
    int counter = 0;
    Matrix *A = new Matrix(2,2);
    Matrix *B = new Matrix(2,2);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            A->insert(i,j,counter++);
            B->insert(i,j,counter++);
        }
    }
    std::cout << "Matrix A: \n" << *A << std::endl;
    std::cout << "Matrix B: \n" << *B << std::endl;

    Matrix T = (*A)^'T';
    std::cout << "A^T: \n" << T << std::endl;

    Matrix D = (*A * *B);
    std::cout << "A * B:\n" << D << std::endl;

    Matrix Z = (*A + *B);
    std::cout << "A + B: \n" << Z << std::endl;

    Matrix S = (*A - *B);
    std::cout << "A - B: \n" << S << std::endl;

    delete A;
    return 0;
}
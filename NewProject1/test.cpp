#include <iostream>
#include "Matrix.h"

int main(){
    Matrix B(3,3);
    Matrix A = B.fillMatrix();

    std::cout << "\e[1mTesting Copy Const\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix copy(A);
    std::cout << copy << std::endl;

    std::cout << "\e[1mTesting Overloaded Assignment Operator\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix ass = A;
    std::cout << ass << std::endl;

    std::cout << "\e[1mTesting insert function\e[0m" << std::endl;
    std::cout << std::endl;
    A.insert(1,1,9);
    std::cout << A << std::endl;

    std::cout << "\e[1mTesting getVal function\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Getting value at A[1][1]" << std::endl;
    double val = A.getVal(1,1);
    std::cout << "Value returned from A[1][1]: " << val << std::endl;
    std::cout << std::endl;

    std::cout << "\e[1mTesting isSymmetric function\e[0m" << std::endl;
    std::cout << std::endl;
    bool flag = A.isSymmetric();
    if(flag == 1){
        std::cout << "It is TRUE that A is symmetric" << std::endl;
        std::cout << std::endl;
    }
    else{
        std::cout << "It is FALSE that A is symmetric" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "\e[1mTesting identityMatrix function\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix Id(5,5);
    Id.identityMatrix();
    std::cout << Id << std::endl;

    std::cout << "\e[1mTesting diagonalMatrix function\e[0m" << std::endl;
    std::cout << std::endl;
    Matrix dia(5,5);
    dia.diagonalMatrix();
    std::cout << dia << std::endl;

    std::cout << "\e[1mTesting triangularMatrix function\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Upper Triangle" << std::endl;
    std::cout << std::endl;
    Matrix upper(5,5);
    upper.triangularMatrix(true);
    upper.printMatrix();
    std::cout << "Lower Triangle" << std::endl;
    std::cout << std::endl;
    Matrix lower(5,5);
    lower.triangularMatrix(false);
    lower.printMatrix();

    std::cout << "\e[1mTesting Matrix Addition\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Matrix S" << std::endl;
    std::cout << std::endl;
    Matrix S(3,3);
    S = S.fillMatrix();
    std::cout << S << std::endl;
    std::cout << "Matrix T" << std::endl;
    std::cout << std::endl;
    Matrix T(3,3);
    T = T.fillMatrix2();
    std::cout << T << std::endl;
    std::cout << "Addition..." << std::endl;
    std::cout << std::endl;
    Matrix ST = S + T;
    std::cout << ST << std::endl;

    std::cout << "\e[1mTesting Matrix Subtraction\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Matrix E" << std::endl;
    std::cout << std::endl;
    Matrix E(3,3);
    E = E.fillMatrix();
    std::cout << S << std::endl;
    std::cout << "Matrix G" << std::endl;
    std::cout << std::endl;
    Matrix G(3,3);
    G = G.fillMatrix2();
    std::cout << G << std::endl;
    std::cout << "Subtracting..." << std::endl;
    std::cout << std::endl;
    Matrix EG = E - G;
    std::cout << EG << std::endl;

    std::cout << "\e[1mTesting Matrix Multiplication\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Matrix U" << std::endl;
    std::cout << std::endl;
    Matrix U(3,3);
    U = U.fillMatrix();
    std::cout << U << std::endl;
    std::cout << "Matrix V" << std::endl;
    std::cout << std::endl;
    Matrix V(3,3);
    V = V.fillMatrix2();
    std::cout << V << std::endl;
    std::cout << "Multiplying..." << std::endl;
    std::cout << std::endl;
    Matrix UV = U * V;
    std::cout << UV << std::endl;

    std::cout << "\e[1mTesting Matrix Scalar Multiplication\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Matrix W" << std::endl;
    std::cout << std::endl;
    Matrix W(3,3);
    W = W.fillMatrix();
    std::cout << W << std::endl;
    std::cout << "Multiplying by 2..." << std::endl;
    std::cout << std::endl;
    Matrix W2 = W * 2;
    std::cout << W2 << std::endl;

    std::cout << "\e[1mTesting Matrix Inverse\e[0m" << std::endl;
    std::cout << std::endl;
    std::cout << "Matrix Q" << std::endl;
    std::cout << std::endl;
    Matrix Q(4,4);
    Q = Q.fillMatrix3();
    Matrix holder = Q;
    std::cout << Q << std::endl;
    std::cout << "Inverse of Matrix Q" << std::endl;
    std::cout << std::endl;
    Matrix Qinv = Q.inverse();
    Qinv.printMatrix();
    std::cout << "Inverse * Matrix Q w/ Normal Print" << std::endl;
    std::cout << std::endl;
    Matrix newNew = Qinv * holder;
    std::cout << newNew << std::endl;
    std::cout << "These numbers represent floating point rounding errors.." << std::endl;
    std::cout << "Therefore the Matrix should look something like this:" << std::endl;
    std::cout << "Inverse * Matrix Q" << std::endl;
    std::cout << std::endl;
    Matrix newQ = Qinv * holder;
    newQ.inversePrint();
    return 0;
}

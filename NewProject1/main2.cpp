#include <iostream>
#include <fstream>
#include "Matrix.h"

// read and report file

Matrix handleFile(std::string fileName){
    std::string firstLevel[100];
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open()){
        std::cout << "ERROR: File not opened!" << std::endl;
        std::exit(1); // need to be careful with this, change to throw catch exceptions
    }
    std::string buffer = " "; // needs to be able to find #
    double buffer2 = 0;
    bool flag = true;
    int i = 0;
    while(buffer != "---"){
        inputFile >> buffer;
        if(buffer == "---"){
            break;
        }
        i++;
    }
    Matrix A(i, i); // creates an i x i Matrix, we can do this based off the project instructions
    for(unsigned long int j = 0; j < i; j++){
        for(unsigned long int k = 0; k < i; k++){
            double num;
            inputFile >> num;
            A.insert(j, k, num);
        }
    }
    std::string nextBuffer, thirdLevel;
    inputFile >> nextBuffer;
    for(int l = 0; l < i; l++){
        inputFile >> thirdLevel;
    }
    inputFile.close(); 
    return A;
}

int main(int argc, char** argv){
    if(argc != 2){
        std::cout <<"You only input 1 parameter, this program takes 2!" << std::endl;
        return 0;
    }
    std::string fileName = argv[1];
    Matrix Q = handleFile(fileName);
    Matrix Holder = Q;
    Matrix Holder2 = Q;

    std::cout << "Matrix A From File" << std::endl;
    std::cout << std::endl;
    Q.printMatrix();

    std::cout << "Matrix A Inverse" << std::endl; // why not working with floats?? NANI!
    std::cout << std::endl;
    Matrix CC = Holder2.inverse();
    CC.printMatrix();

    std::cout << "A * A Inverse" << std::endl;
    std::cout << std::endl;
    Matrix PP = Holder * Q.inverse();
    PP.printMatrix();

    std::cout << "A Identity Matrix" << std::endl;
    std::cout << std::endl;
    Holder.identityMatrix();
    Holder.printMatrix();

    std::cout << "------------------------" << std::endl;

    std::cout << "  Matrix B (Generated)" << std::endl;
    std::cout << std::endl;
    Matrix Y(3,3);
    Matrix Z = Y.fillMatrix();
    Matrix DD = Z;
    Matrix LL = Z;
    Z.printMatrix();

    std::cout << "      B Inverse" << std::endl;
    std::cout << std::endl;
    Matrix inv = LL.inverse();
    inv.printMatrix();

    std::cout << "    B * B Inverse" << std::endl;
    std::cout << std::endl;
    Matrix done = DD * Z.inverse();
    done.printMatrix(); 
    
    std::cout << "   B Identity Matrix" << std::endl;
    std::cout << std::endl;
    DD.identityMatrix();
    DD.printMatrix();

    std::cout << "------------------------" << std::endl;

    return 0;
}
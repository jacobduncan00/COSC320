#include <iostream>
#include <fstream>
#include "Matrix.h"

// read and report file

Matrix handleFile(std::string fileName){
    // Coal
    // Electricity
    // Produce
    // ---
    // 0.6 0.02 0.1         How input file will look
    // 0.3 0.2 0.4
    // 0.2 0.4 0.3
    // ---
    // 20
    // 34
    // 80

    std::string firstLevel[100];
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open()){
        std::cout << "ERROR: File not opened!" << std::endl;
        std::exit(1); // need to be careful with this, change to throw catch exceptions
    }
    std::string buffer = " "; // needs to be able to find #
    float buffer2 = 0;
    bool flag = true;
    int i = 0;
    while(buffer != "---"){
        inputFile >> buffer;
        if(buffer == "---"){
            // std::cout << std::endl;
            // std::cout << "Buffer: " << buffer << std::endl;
            break;
        }
        // std::cout << buffer << std::endl;
        i++;
    }
    // std::cout << std::endl;
    // std::cout << "Matrix will be " << i << "x" << i << std::endl;
    // std::cout << std::endl;
    // std::cout << "      Matrix   " << std::endl;
    // std::cout << "   ------------" << std::endl;
    // std::cout << std::endl;
    Matrix A(i, i); // creates an i x i Matrix, we can do this based off the project instructions
    for(unsigned long int j = 0; j < i; j++){
        for(unsigned long int k = 0; k < i; k++){
            float num;
            inputFile >> num;
            A.insert(j, k, num);
        }
    }
    //A.printMatrix();
    std::string nextBuffer, thirdLevel;
    inputFile >> nextBuffer;
    //std::cout << "Buffer: " << nextBuffer << std::endl;
    //std::cout << std::endl;
    for(int l = 0; l < i; l++){
        inputFile >> thirdLevel;
        //std::cout << thirdLevel << std::endl;
    }
    inputFile.close(); 
    return A;
}

int main(int argc, char** argv){
    if(argc != 2){
        std::cout << "You only input 1 parameter, this program takes 2!" << std::endl;
        return 0;
    }
    std::string fileName = argv[1];
    Matrix A = handleFile(fileName);
    Matrix Holder = A;
    Matrix A_identity = handleFile(fileName);
    Matrix B = A;

    std::cout << "Matrix A From File" << std::endl;
    std::cout << std::endl;
    A.printMatrix();

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
#include <iostream>
#include <fstream>
#include "Matrix.h"

// read and report file

Matrix calcData(Matrix& in, Matrix& dem){
    Matrix id = in.identityMatrix();  
    Matrix rtn = ((id - in).inverse()) * (dem);
    return rtn;
}

void handleFile(std::string fileName){
    std::string firstLevel[100];
    std::ifstream inputFile(fileName);
    if(!inputFile.is_open()){
        std::cout << "ERROR: File not opened!" << std::endl;
        std::exit(1); // need to be careful with this, change to throw catch exceptions
    }
    std::string buffer = " "; // needs to be able to find #
    std::string names[3];
    int dim = 0;
    do{
        inputFile >> buffer;
        if(buffer == "---"){                    // used to catch the ---
            break;
        }
        names[dim] = buffer;
        dim++;
    }while(buffer != "---");

    std::cout << "Dimensions: " << dim << std::endl;
    Matrix A(dim, dim);
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            double num;
            inputFile >> num;
            A.insert(i, j, num);
        }
    }

    std::string buffer2 = " ";
    inputFile >> buffer;                          // used to catch the ---
    std::cout << buffer2 << std::endl;

    double demandArr[dim];
    Matrix demand(dim, 1);
    for(int i = 0; i < dim; i++){
        double num2;
        inputFile >> num2;
        demandArr[i] = num2;
        demand.insert(i, 0, num2);
    }
    inputFile.close();
    std::cout << std::endl;
    std::cout << "First Level Contents:" << std::endl;
    std::cout << std::endl;
    for(int i = 0; i < 3; i++){
        std::cout << names[i] << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Second Level Contents:" << std::endl;
    std::cout << std::endl;
    std::cout << A << std::endl;

    std::cout << "Third Level Contents:" << std::endl;
    std::cout << std::endl;
    std::cout << demand << std::endl;

    std::cout << "Amount of each producted needed:" << std::endl;
    Matrix temp = calcData(A, demand); 
    for(int i = 0; i < dim; i++){
        Matrix temp = calcData(A, demand);
        std::cout << names[i] << ":     " << temp << std::endl;
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        std::cout <<"You only input 1 parameter, this program takes 2!" << std::endl;
        return 0;
    }
    std::string fileName = argv[1];
    handleFile(fileName);
    return 0;
}
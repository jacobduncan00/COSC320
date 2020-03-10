#include <iostream>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

Matrix calcDemand(Matrix& in, Matrix& dem){
    Matrix id = in;
    id.identityMatrix();
    Matrix rtn = ((id - in).inverse()) * (dem);
    return rtn;
}

int main(int argc, char** argv){
    if(argc != 2){
        std::cout <<"You only input 1 parameter, this program takes 2!" << std::endl;
        return 0;
    }
    std::ifstream inFile;
    try{
        inFile.open(argv[1]);
    } catch (...){
        std::perror("ERROR: Input file not opened.");
        return 0;
    }

    int dimensions = 0;
    std::string firstLevelNames[50];
    bool flag = false;
    while(inFile.peek() != EOF){
        std::cout << "First Level: " << std::endl;
        std::cout << std::endl;
        for(int i = 0; inFile.peek() != '-'; i++){
            std::getline(inFile, firstLevelNames[i]);
            std::cout << firstLevelNames[i] << std::endl;
            dimensions++;
        }
        std::cout << std::endl;
        std::cout << "Second Level: " << std::endl;
        std::cout << std::endl;
        inFile.ignore(3, '\n');
        Matrix fileMatrix(dimensions, dimensions);
        double insertNum = 0;
        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                inFile >> insertNum;
                fileMatrix.insertNum(i, j, insertNum);
            }
        }
        std::cout << fileMatrix << std::endl;
        std::cout << "Third Level: " << std::endl;
        std::cout << std::endl;
        inFile.ignore(5, '\n');
        inFile.ignore(5, '\n');
        Matrix demand(dimensions, 1);
        double insertNum2 = 0;
        for(int i = 0; i < dimensions; i++){
            inFile >> insertNum2;
            demand.insertNum(i, 0, insertNum2);
        }
        std::cout << demand << std::endl;
        std::cout << "================================" << std::endl;
        std::cout << "Amount of each producted needed:" << std::endl;
        Matrix result = calcDemand(fileMatrix, demand); 
        for(int i = 0; i < dimensions; i++){
            double matrixReturn = result.getVal(i, 0);
            std::cout << firstLevelNames[i] << ": " << matrixReturn << " units" << std::endl;
        }
        std::cout << "================================" << std::endl;
        inFile.ignore(5, '\n');
        inFile.ignore(5, '\n');
        insertNum = 0;
        insertNum2 = 0;
    }
    inFile.close();
    return 0;
}
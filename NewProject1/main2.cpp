#include <iostream>
#include <fstream>
//#include "Matrix.h"

// read and report file

void handleFile(std::string fileName){
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
    int buffer = 10; // needs to be able to find #
        // first level
    for(int i = 0; i < buffer; i++){
        if(i == 3){
            std::string level2buffer = " ";
            inputFile >> level2buffer;
            std::cout << level2buffer << std::endl;
        }
        if (i > 3){
            std::string idk;
            std::getline(inputFile, idk);
            for(int i = 0; i < idk.length(); i++){
                float num = 0;
                input
            }
            std::cout << idk << std::endl;
        }
        if(i < 2){
            std::string line;
            inputFile >> line;
            firstLevel[i] = line;
            std::cout << firstLevel[i] << std::endl;
        }  
    }
    inputFile.close(); 
    // second level
    // get line, then line length, then store each in vector
}

int main(int argc, char** argv){
    std::string fileName = argv[1];
    handleFile(fileName);
    return 0;
}
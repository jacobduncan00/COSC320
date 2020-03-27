#include <iostream>
#include <fstream>
#include <iomanip>
#include "Matrix.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLDBLACK   "\033[1m\033[30m"
#define BOLDRED     "\033[1m\033[31m"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDYELLOW  "\033[1m\033[33m"
#define BOLDBLUE    "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN    "\033[1m\033[36m"
#define BOLDWHITE   "\033[1m\033[37m"

Matrix calcDemand(Matrix& in, Matrix& dem){
    Matrix id = in;
    id.identityMatrix();
    Matrix rtn = ((id - in).inverse()) * (dem);
    return rtn;
}

void welcomeScreen(){
    std::cout << BOLDRED << "**************************************" << RESET << std::endl;
    std::cout << BOLDRED << "**************************************" << RESET << std::endl;
    std::cout << BOLDRED << "**                                  **" << RESET << std::endl;
    std::cout << BOLDRED << "**             WELCOME              **" << RESET << std::endl;
    std::cout << BOLDRED << "**        TO YOUR SUPPLY &          **" << RESET << std::endl;
    std::cout << BOLDRED << "**       DEMAND CALCULATOR BY       **" << RESET << std::endl;
    std::cout << BOLDRED << "**           JACOB DUNCAN           **" << RESET << std::endl;
    std::cout << BOLDRED << "**                                  **" << RESET << std::endl;
    std::cout << BOLDRED << "**************************************" << RESET << std::endl;
    std::cout << BOLDRED << "**************************************" << RESET << std::endl;
}

int main(int argc, char** argv){

    welcomeScreen();

    if(argc != 2){
        std::cout <<"You only input 1 parameter, this program takes 2!" << std::endl;
        return 0;
    }

    std::ifstream inFile;

    try{
        // attempts to open file
        inFile.open(argv[1]);
    } catch (...){
        // if cannot be opened print error and end program, cannot run with no data
        std::perror("ERROR: Input file not opened.");
        return 0;
    }

    int dimensions = 0;
    // company limit is 1000, please don't go over 1000 Dr. Anderson
    std::string firstLevelNames[1000];
    while(inFile.peek() != EOF){
        std::cout << BOLDRED << "First Level: " << RESET << std::endl;
        std::cout << std::endl;
        for(int i = 0; inFile.peek() != '-'; i++){
            std::getline(inFile, firstLevelNames[i]);
            std::cout << firstLevelNames[i] << std::endl;
            dimensions++;
        }
        std::cout << std::endl;
        std::cout << BOLDRED << "Second Level: " << RESET << std::endl;
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
        std::cout << BOLDRED << "Third Level: " << RESET << std::endl;
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
        std::cout << BOLDRED << "================================" << std::endl;
        std::cout << "Amount of each producted needed:" << std::endl;
        Matrix result;
        try{
            result = calcDemand(fileMatrix, demand);
        }
        catch(std::string errorMessage){
            std::cout << errorMessage << std::endl;
        }
        for(int i = 0; i < dimensions; i++){
            double matrixReturn = result.getVal(i, 0);
            std::cout << BOLDRED << firstLevelNames[i] << ": " << RESET << matrixReturn << " units" << std::endl;
        }
        std::cout << BOLDRED << "================================" << RESET << std::endl;
        inFile.ignore(5, '\n');
        inFile.ignore(5, '\n');
        insertNum = 0;
        insertNum2 = 0;
    }
    inFile.close();
    return 0;
}

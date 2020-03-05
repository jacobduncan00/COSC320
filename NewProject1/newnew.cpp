#include <iostream>
#include <fstream>
#include "Matrix.h"

// read and report file

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

    Matrix demand(dim, 1);
    for(int i = 0; i < dim; i++){
        double num2;
        inputFile >> num2;
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

    std::cout << "Testing Copy Const" << std::endl;
    std::cout << std::endl;
    Matrix copy(A);
    std::cout << copy << std::endl;

    std::cout << "Testing Overloaded Assignment Operator" << std::endl;
    std::cout << std::endl;
    Matrix ass = A;
    std::cout << ass << std::endl;

    std::cout << ""
    //A.printMatrix();
    /*
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
    */
}

Matrix calcData(Matrix& in, Matrix& dem){
    Matrix id = in;
    id.identityMatrix();
    Matrix rtn = (id - in).inverse() * dem;
    return rtn;
}

int main(int argc, char** argv){
    if(argc != 2){
        std::cout <<"You only input 1 parameter, this program takes 2!" << std::endl;
        return 0;
    }
    std::string fileName = argv[1];
    handleFile(fileName);
    /*
    Matrix Holder = Q;
    Matrix Holder2 = Q;

    std::cout << "Testing Copy Const" << std::endl;
    std::cout << std::endl;
    Matrix TY(Q);
    TY.printMatrix();

    std::cout << "Testing Assignment Operator" << std::endl;
    std::cout << std::endl;
    Matrix TT = TY;
    TT.printMatrix();

    std::cout << "Matrix A From File" << std::endl;
    std::cout << std::endl;
    Q.printMatrix();

    std::cout << "Matrix A Inverse" << std::endl; 
    std::cout << std::endl;
    Matrix CC = Holder2.inverse();
    CC.printMatrix();

    std::cout << "A * A Inverse" << std::endl;
    std::cout << std::endl;
    Matrix PP = Holder * Q.inverse();
    std::cout << PP << std::endl;

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

    Matrix mm = handleFile(fileName);
    Matrix dim(3,1);
    std::cout << "Original Demand Vector" << std::endl;
    dim.printMatrix();
    Matrix tmp = mm.inverse();
    */
    return 0;
}
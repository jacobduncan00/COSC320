#include "matrix.h"
#include <iostream>

// int argc, char** argv
int main(int argc, char** argv){
    std::string fileName = argv[1];
	Matrix T;
    T.TwoDRegression(fileName);
}

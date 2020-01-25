#include "matrix.h"

// int argc, char** argv
int main(int argc, char** argv){
    std::string fileName = argv[0];
	Matrix T;
    T.TwoDRegression(fileName);
}

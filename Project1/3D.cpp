#include "matrix.h"

int main(int argc, char** argv){
  std::string fileName = argv[1];
  Matrix Z;
  Z.ThreeDRegression(fileName);
}
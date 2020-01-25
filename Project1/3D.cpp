#include "matrix.h"

int main(int argc, char** argv){
  std::string fileName = argv[0];
  Matrix Z;
  Z.ThreeDRegression(fileName);
}
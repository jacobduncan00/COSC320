#include <iomanip>
#include <iostream>
#include <math.h>

size_t hash(size_t);
void printHash(size_t);
size_t hashTest1(std::string);
size_t hashTest2(std::string);

size_t hash(size_t x){
    size_t w = pow(2, 64);
    size_t p = 53;
    size_t a = 3533;
    size_t rtn = floor((a * x % w)/pow(2, w-p));
    return rtn;
}

void printHash(size_t num){
  std::cout << "Hash: " << std::hex << num << std::endl;
}

size_t hashTest1(std::string str){
  size_t temp = 0;
  for(int i = 0; i < str.length(); i++){
    temp += (int)str[i];
  }
}

size_t hastTest2(std::string str){
  size_t oddNum = 151;
  unsigned long int rtn = 0;
  for(int i = 0; i < str.length(); i++){
    rtn = (rtn * oddNum) + str[i];
  }
  return rtn % 531;
}

int main(){
  std::cout << "Testing integer hashing:" << std::endl;
  std::cout << "-> Int: " << 5 << std::endl;
  printHash(hash(5));
  return 0;
}


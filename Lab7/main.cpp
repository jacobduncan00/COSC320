#include <iomanip>
#include <iostream>
#include <math.h>

size_t hash(size_t);
void printHash(size_t);
size_t hashTest1(std::string);
size_t hashTest2(std::string);

size_t hash(size_t x){
    size_t w = size_t(pow(2, 64));
    size_t p = 53;
    size_t a = 3533;
    size_t rtn = floor((a * x % w)/pow(2, 64-p));
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
  return temp % 531;
}

size_t hastTest2(std::string str){
  size_t oddNum = 151;
  unsigned long long rtn = 0;
  for(int i = 0; i < str.length(); i++){
    rtn = (rtn * oddNum) + str[i];
  }
  return rtn % 531;
}

int main(){
  std::cout << "Testing hashing ints:" << std::endl;
  std::cout << "---------------------" << std::endl;
  std::cout << "Int: " << 5 << " | ";
  printHash(hash(5));
  std::cout << "Int: " << 100 << " | ";
  printHash(hash(100));
  std::cout << "Int: " << 5000 << " | ";
  printHash(hash(5000));
  std::cout << "Int: " << 100000 << " | ";
  printHash(hash(100000));
  std::cout << "---------------------" << std::endl;
  std::cout << "Int: " << 5 << " | ";
  printHash(hash(5));
  std::cout << "---------------------" << std::endl;
  std::cout << "Testing hashing strings:" << std::endl;
  std::cout << "------------------------" << std::endl;
  std::cout << "String: I am a COSC major" << std::endl;
  printHash(hashTest1("I am a COSC major"));
  std::cout << "String: Coronavirus" << std::endl;
  printHash(hashTest1("Coronavirus"));
  std::cout << "String: We are using zoom" << std::endl;
  printHash(hashTest1("We are using zoom"));
  std::cout << "------------------------" << std::endl;
  std::cout << "String: I am a COSC major" << std::endl;
  printHash(hashTest1("I am a COSC major"));
  std::cout << "------------------------" << std::endl;

  return 0;
}


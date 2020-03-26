#include<iostream>
#include "bt.h"

int main(){
  BinaryTree t;
  t.insert(10);
  t.insert(7);
  t.insert(3);
  if(t.search(7) == 1){
    std::cout << "7 is present" << std::endl;
  }
  t.print();
  return 0;
}

#include<iostream>
#include "bt.h"

// Lab 8 by Jacob Duncan @ Salisbury University
// Completed 3/28/2020
// Program that uses Binary Trees
// and the print, inorder, insert, search,
// max, min, and successor function

int main(){
  BinaryTree t;
  std::cout << "Testing Insert: " << std::endl;
  std::cout << "Inserting 3,4,7,3,5,1...";
  t.insert(3);
  t.insert(4);
  t.insert(7);
  t.insert(3);
  t.insert(5);
  t.insert(1);
  std::cout << "Insertion successful!" << std::endl;
  std::cout << std::endl;
  std::cout << "Printing 'inorder': ";
  t.inorder();
  std::cout << std::endl;
  std::cout << "Printing 'preorder': ";
  t.print();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Testing Copy Constructor" << std::endl;
  std::cout << "Current BT: ";
  t.inorder();
  std::cout << std::endl;
  std::cout << "Printing Copy: ";
  BinaryTree c(t);
  c.inorder();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Testing Assignment Operator" << std::endl;
  std::cout << "Current BT: ";
  c.inorder();
  std::cout << std::endl;
  std::cout << "Printing Assigned: ";
  BinaryTree a = c;
  a.inorder();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Testing Minimum" << std::endl;
  std::cout << "Current BT: ";
  a.inorder();
  std::cout << std::endl;
  std::cout << "Minimum: " << a.minimum() << std::endl;
  std::cout << std::endl;
  std::cout << "Testing Maximum" << std::endl;
  std::cout << "Current BT: ";
  a.inorder();
  std::cout << std::endl;
  std::cout << "Maximum: " << a.maximum() << std::endl;
  std::cout << std::endl;
  std::cout << "Testing Search" << std::endl;
  std::cout << "Current BT: ";
  a.inorder();
  std::cout << std::endl;
  std::cout << "Is 4 in BT? ";
  if(a.search(4) == 4){
    std::cout << "Yes" << std::endl;
  }
  a.search(4);
  std::cout << "Is 9 in BT? ";
  if(a.search(9) == 9){
    std::cout << "Yes" << std::endl;  
  }
  std::cout << std::endl;
  std::cout << "Testing Successor" << std::endl;
  a.insert(9);
  a.insert(8);
  a.insert(2);
  std::cout << "Current BT: ";
  a.inorder();
  std::cout << std::endl;
  std::cout << "5's successor: " << a.successor(5) << std::endl;
  std::cout << "1's successor: " << a.successor(1) << std::endl;
  return 0;
}

#include<iostream>
#include <chrono>
#include "bt.h"

// Lab 8 by Jacob Duncan @ Salisbury University
// Completed 3/28/2020
// Program that uses Binary Trees
// and the print, inorder, insert, search,
// max, min, successor, remove, and transplant function

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
  std::cout << std::endl;
  std::cout << "Testing Removing Node" << std::endl;
  std::cout << "Removing 5" << std::endl;
  a.removeNode(5);
  std::cout << "Current BT: ";
  a.inorder();
  std::cout << std::endl;
  std::cout << "Removing 9" << std::endl;
  a.removeNode(9);
  std::cout << "Current BT: ";
  a.inorder();
  std::cout << std::endl;

  std::cout << std::endl;
  // Timing for Insert, Search, Delete
  std::cout << " INSERT TEST " << std::endl;
  std::cout << std::endl;
  BinaryTree ins;
  int values[20] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000,
  5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000};
  for(int i = 0; i < 20; i++){
    std::cout << "Inserting " << values[i] << " into the Binary Tree" << std::endl;
    auto start = std::chrono::system_clock::now();
    for(int j = 0; j < values[i]; j++){
      ins.insert((rand()%10)+1);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double>elapsed_seconds = end -start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "-> " << elapsed_seconds.count() << "s" <<  std::endl;
  }

  std::cout << std::endl;
  // Timing for Search
  std::cout << " SEARCHING TEST " << std::endl;
  std::cout << std::endl;
  BinaryTree ser;
  for(int i = 0; i < 20; i++){
    std::cout << "Searching " << values[i] << " in the Binary Tree" << std::endl;
    for(int j = 0; j < values[i]; j++){
      ser.insert((rand()%500)+1);
    }
    auto start = std::chrono::system_clock::now();

    std::cout << "-> Key: " << ser.search((rand()%500)+1) << std::endl;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double>elapsed_seconds = end -start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "-> " << elapsed_seconds.count() << "s" <<  std::endl;
  }

  std::cout << std::endl;
  // Timing for Deleting
  std::cout << " DELETE TEST " << std::endl;
  std::cout << std::endl;
  BinaryTree del;
  for(int i = 0; i < 20; i++){
    std::cout << "Deleting " << values[i] << " test in the Binary Tree" << std::endl;
    for(int j = 0; j < values[i]; j++){
      del.insert((rand()%500)+1);
    }
    auto start = std::chrono::system_clock::now();

    del.removeNode((rand()%500)+1);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double>elapsed_seconds = end -start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "-> " << elapsed_seconds.count() << "s" <<  std::endl;
  }
  return 0;
}

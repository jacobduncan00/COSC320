#include <iostream>
#include <chrono>
#include "rb.h"

int main()
{
  RBTree tree;
  std::cout << "Inserting: 1, 6, 4, 2, 7, 10" << std::endl;
  tree.insert(1);
  tree.insert(6);
  tree.insert(4);
  tree.insert(2);
  tree.insert(7);
  tree.insert(10);
  std::cout << "Printing Tree in order" << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << "Printing normally (tree format)" << std::endl;
  tree.print();
  std::cout << std::endl;
  std::cout << std::endl;

  // If return value equals the value searched for, then the key is in the tree
  // else, if the return value is -1, the key is not in the tree
  std::cout << "--------------------------------" << std::endl;
  std::cout << "Searching for 6. Return value: ";
  int sixReturn = tree.searchTree(6);
  std::cout << sixReturn << std::endl;
  std::cout << "Searching for 19. Return value: ";
  int nineteenReturn = tree.searchTree(19);
  std::cout << nineteenReturn << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "--------------------------------" << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Max of the Tree: " << tree.findMax() << std::endl;
  std::cout << "Min of the Tree: " << tree.findMin() << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "--------------------------------" << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Successor of 6: " << tree.findSucc(6) << std::endl;
  std::cout << "Successor of 2: " << tree.findSucc(2) << std::endl;
  std::cout << "Successor of 19: " << tree.findSucc(19) << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "--------------------------------" << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << "Deleting 6" << std::endl;
  tree.delNode(6);
  std::cout << "Result: " << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << "Deleting 10" << std::endl;
  tree.delNode(10);
  std::cout << "Result: " << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << "Deleting 1" << std::endl;
  tree.delNode(1);
  std::cout << "Result: " << std::endl;
  tree.inOrder();
  std::cout << std::endl;
  std::cout << std::endl;

  // Timing for Insert, Search, Delete
  std::cout << " INSERT TEST " << std::endl;
  std::cout << std::endl;
  RBTree ins;
  int values[20] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000,
                    5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000, 9500, 10000};
  for (int i = 0; i < 20; i++)
  {
    std::cout << "Inserting " << values[i] << " into the Red-Black Tree" << std::endl;
    auto start = std::chrono::system_clock::now();
    for (int j = 0; j < values[i]; j++)
    {
      ins.insert((rand() % values[i]) + 1);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "-> " << elapsed_seconds.count() << "s" << std::endl;
  }

  std::cout << std::endl;
  // Timing for Search
  std::cout << " SEARCHING TEST " << std::endl;
  std::cout << std::endl;
  RBTree ser;
  for (int i = 0; i < 20; i++)
  {
    std::cout << "Searching " << values[i] << " in the Red-Black Tree" << std::endl;
    for (int j = 0; j < values[i]; j++)
    {
      ser.insert((rand() % values[i]) + 1);
    }
    auto start = std::chrono::system_clock::now();

    std::cout << "-> Key: " << ser.searchTree((rand() % values[i]) + 1) << std::endl;

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "-> " << elapsed_seconds.count() << "s" << std::endl;
  }
  std::cout << std::endl;
  // Timing for Deleting
  std::cout << " DELETE TEST " << std::endl;
  std::cout << std::endl;
  RBTree del;
  for (int i = 0; i < 20; i++)
  {
    std::cout << "Deleting " << values[i] << " test in the Red-Black Tree" << std::endl;
    for (int j = 0; j < values[i]; j++)
    {
      del.insert((rand() % values[i]) + 1);
    }
    auto start = std::chrono::system_clock::now();

    del.delNode((rand() % values[i]) + 1);

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "-> " << elapsed_seconds.count() << "s" << std::endl;
  }
  return 0;
}
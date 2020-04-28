#include <iostream>
#include "Graph.h"

int main()
{
  Graph g;
  std::cout << "Adding vertices to the graph: 5, 9, -4, 8, 2, 2" << std::endl;
  std::cout << "-----------------------------------------------" << std::endl;
  g.addVertex(5);
  g.addVertex(9);
  g.addVertex(-4);
  g.addVertex(8);
  g.addVertex(2);
  // Adding the same vertex twice to show it will not be added and error message displayed
  g.addVertex(2);
  std::cout << std::endl;
  std::cout << "Printing vertices and connections" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << std::endl;
  g.print();
  std::cout << std::endl;

  std::cout << "Adding edges to the graph: (8, -4), (5, 9), (2, 9), (8, 9), (9, 9)" << std::endl;
  std::cout << "------------------------------------------------------------------" << std::endl;
  g.addEdge(8, -4);
  g.addEdge(5, 9);
  g.addEdge(2, 9);
  g.addEdge(8, 9);
  // Adding a self edge to show it will not be added and error message displayed
  g.addEdge(9, 9);
  std::cout << std::endl;
  std::cout << "Printing vertices and connections" << std::endl;
  std::cout << "---------------------------------" << std::endl;
  std::cout << std::endl;
  g.print();
  std::cout << std::endl;

  std::cout << "Using Breadth-First-Search to find 9 in the graph!" << std::endl;
  std::cout << "--------------------------------------------------" << std::endl;
  g.printBfs(9);
  return 0;
}
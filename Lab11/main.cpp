#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.h"

int main(int argc, char**argv){
  Graph g;
  if(argc != 2){
    std::cout << "Program expects 2 parameters, seems like you are missing the text file!" << std::endl;
    exit(1);
  }
  std::ifstream inputFile("AdjacencyList.txt");
  if(!inputFile.is_open()){
    std::cout << "ERROR: File not opened properly!" << std::endl;
    exit(1);
  }
  std::string line;
  if(inputFile.is_open()){
    while(std::getline(inputFile, line)){
        std::istringstream stream(line);
        int a;
        int b;
        stream >> a;
        g.addVertex(a);
        while(stream >> b){
          g.addVertex(b);
          g.addEdge(a, b);
        }
    }
  }
  std::cout << std::endl;
  std::cout << "Printing Graph" << std::endl;
  std::cout << "--------------" << std::endl;
  g.print();
  std::cout << std::endl;
  std::cout << "Inserting Vertices: 10, 4, 18, 9, 2" << std::endl;
  g.addVertex(10);
  g.addVertex(4);
  g.addVertex(18);
  g.addVertex(9);
  g.addVertex(2);
  g.addVertex(20);
  g.addVertex(15);
  g.addVertex(1);
  g.addVertex(11);
  g.addVertex(19);
  std::cout << std::endl;
  std::cout << "Printing Graph" << std::endl;
  std::cout << "--------------" << std::endl;
  g.print();
  std::cout << "Creating Edges: (10, 2), (9, 9), (18, 6)" << std::endl;
  g.addEdge(10, 2);
  g.addEdge(9, 9);
  g.addEdge(18, 6);
  g.addEdge(19, 4);
  g.addEdge(20, 15);
  g.addEdge(15, 10);
  g.addEdge(5, 19);
  g.addEdge(1, 18);
  std::cout << std::endl;
  std::cout << "Printing Graph" << std::endl;
  std::cout << "--------------" << std::endl;
  g.print();

  std::cout << std::endl;
  std::cout << "Performing DFS" << std::endl;
  std::cout << "--------------" << std::endl;
  g.printDFS();

  std::cout << std::endl;
  Graph topo;
  topo.addVertex(5);
  topo.addVertex(2);
  topo.addVertex(10);
  topo.addVertex(12);
  topo.addVertex(1);
  topo.addEdge(5, 2);
  topo.addEdge(5, 1);
  topo.addEdge(1, 10);
  topo.addEdge(10, 12);
  std::cout << std::endl;
  std::cout << "New Current Graph" << std::endl;
  std::cout << "--------------" << std::endl;
  topo.print();
  std::cout << std::endl;
  std::cout << "Performing TOPO sort" << std::endl;
  std::cout << "--------------------" << std::endl;
  topo.printTOPO();

  std::cout << std::endl;
  std::cout << "Performing SCC print" << std::endl;
  std::cout << "--------------------" << std::endl;
  g.printSCC();



  return 0;
}

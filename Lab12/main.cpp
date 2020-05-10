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
  std::cout << "Cover Print" << std::endl;
  std::cout << "-----------" << std::endl;
  g.printCOVER();

  std::cout << std::endl;
  std::cout << "Cover Random Print" << std::endl;
  std::cout << "------------------" << std::endl;
  g.printCOVERRANDOM();

  std::cout << std::endl;
  std::cout << "Cover Brute Print" << std::endl;
  std::cout << "-----------------" << std::endl;
  g.printCOVERBRUTE();

  std::cout << std::endl;
  Graph g2;
  g2.addVertex(1);
	g2.addVertex(2);
	g2.addVertex(3);
	g2.addVertex(4);
	g2.addVertex(5);
	g2.addVertex(6);
	g2.addEdge(1, 2);
	g2.addEdge(1, 3);
	g2.addEdge(1, 4);
	g2.addEdge(2, 6);
	g2.addEdge(2, 5);
	g2.addEdge(3, 4);
	g2.addEdge(4, 6);
	g2.addEdge(5, 6);
  g2.addEdge(6, 1);
  std::cout << std::endl;
  std::cout << "Printing New Graph" << std::endl;
  std::cout << "------------------" << std::endl;
  g2.print();
  std::cout << std::endl;
  std::cout << "Cover Print" << std::endl;
  std::cout << "-----------" << std::endl;
  g2.printCOVER();

  std::cout << std::endl;
  std::cout << "Cover Random Print" << std::endl;
  std::cout << "------------------" << std::endl;
  g2.printCOVERRANDOM();

  std::cout << std::endl;
  std::cout << "Cover Brute Print" << std::endl;
  std::cout << "-----------------" << std::endl;
  g2.printCOVERBRUTE();

  return 0;
}

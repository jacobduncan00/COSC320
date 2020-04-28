#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include <queue>

enum color_t
{
  Black,
  Gray,
  White
};

class Graph
{
private:
  std::map<int, std::vector<int>> vertices;
  void genGrid(std::map<int, color_t> &, std::map<int, int> &);

public:
  void addVertex(int);
  void addEdge(int, int);
  void print();
  void printBfs(int);
};

#endif
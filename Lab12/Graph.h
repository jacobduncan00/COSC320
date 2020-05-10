#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <algorithm>
#include <limits>
#include <map>
#include <vector>
#include <queue>

// Colors used by nodes in graph
enum color_t {
  Black, Gray, White
};

class Graph {

  private:

    int timer;
    std::map<int, int> finalTime;
    std::map<int, std::vector<int>> vertices;
    std::vector<std::pair<int, int>>edges;
    // Determine whether a graph is a DAG or not, used in constructor
    bool dag;

    // Generates grid for the search algorithms
    void genGrid(std::map<int, color_t>&, std::map<int, int>&, std::map<int, int>&);
    // DFS modified search
    void dfsVisit(int, std::map<int, color_t>&, std::map<int, int>&, std::map<int, int>&);
    // DFS modified SCC search
    void dfsSCCVisit(int, std::map<int, color_t>&);
    // DFS SCC in Graph
    void dfsSCC(std::vector<std::pair<int, int>>);

  public:
    Graph();
    void addVertex(int);
    void addEdge(int, int);
    void print();
    void printBFS(int);
    void printDFS();
    void printTOPO();
    void printSCC();
    bool isCover(std::vector<int>);
    void printCOVER();
    void printCOVERRANDOM();
    void printCOVERBRUTE();
};

#endif

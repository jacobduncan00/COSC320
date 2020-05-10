#include "Graph.h"

// Default constructor that initializes a dag to be true

Graph::Graph(){
  dag = true;
}

// Something is wrong with the parents not keeping track of the values
void Graph::genGrid(std::map<int, color_t>& col, std::map<int, int>& dist, std::map<int, int>& par){
  std::map<int, std::vector<int>>::iterator count;
  for(count = vertices.begin(); count != vertices.end(); ++count){
    col.insert(std::pair<int, color_t>((*count).first, White));
    dist.insert(std::pair<int, int>((*count).first, std::numeric_limits<int>::max()));
    par.insert(std::pair<int, int>((*count).first, std::numeric_limits<int>::max()));
  }
}

// Function that allows a vertex or new "node" to be added into the graph
void Graph::addVertex(int a){
  std::map<int, std::vector<int>>::iterator count;
  count = vertices.find(a);
  if(count != vertices.end()){
    std::cout << "ERROR: " << a << " already appears in the graph!" << std::endl;
    return;
  }
  std::vector<int> edge;
  vertices.insert(std::pair<int, std::vector<int>>(a, edge));
  std::cout << "Vertex " << a << " is now in the graph!" << std::endl;
}

// Function that allows an edge to be made between two vertices that already
// exist in the graph
void Graph::addEdge(int a, int b){
  if (a==b){
    std::cout << "ERROR: Tried to create self edge of (" << a << ", " << b << ")!" << std::endl;
    return;
  }
  std::map<int, std::vector<int>>::iterator count;
  count = vertices.find(a);
  // If vertex a is not found
  if (count == vertices.end()){
    std::cout << "Vertex " << a << " was not found in the graph!" << std::endl;
    return;
  }
  count = vertices.find(b);
  if (count == vertices.end()){
    std::cout << "Vertex " << b << " was not found in the graph!" << std::endl;
    return;
  }
  vertices[a].push_back(b);
}

// Function to print the vertex in the graph and the other vertices they are
// connected to
void Graph::print(){
  for(std::map<int, std::vector<int>>::iterator count = vertices.begin(); count != vertices.end(); ++count){
    std::cout << (*count).first << " is connected to the following vertices: ";
    for(std::vector<int>::iterator vectorCount = (*count).second.begin(); vectorCount != (*count).second.end(); ++vectorCount){
      if(vectorCount == (*count).second.end() - 1){
        std::cout << *vectorCount;
      }
      else {
        std::cout << *vectorCount << ", ";
      }
    }
    std::cout << std::endl;
  }
}

// Function that performs Breadth-First-Search on our graph in order to find the
// shortest path to the node with a specific number

void Graph::printBFS(int s)
{
  std::queue<int> que;
  std::map<int, color_t> color;
  std::map<int, int> dist;
  std::map<int, int> par;
  genGrid(color, dist, par);

  dist[s] = 0;
  color[s] = Gray;
  par[s] = std::numeric_limits<int>::max();
  que.push(s);

  while (!que.empty())
  {
    int temp = que.front();
    que.pop();
    for (std::vector<int>::iterator count = vertices[temp].begin(); count != vertices[temp].end(); ++count)
    {
      if (color[*count] == White)
      {
        color[*count] = Gray;
        dist[*count] = dist[temp] + 1;
        par[*count] = temp;
        que.push(*count);
      }
      color[temp] = Black;
    }
  }

  std::map<int, color_t>::iterator count2 = color.begin();
  std::map<int, int>::iterator par2 = par.begin();
  std::map<int, int>::iterator dist2 = dist.begin();
  for (int i = 0; count2 != color.end(); ++count2, ++dist2, i++)
  {
    std::cout << "Vertex: " << (*count2).first << std::endl;
    if ((*count2).second == 0)
    {
      std::cout << "Color: Black" << std::endl;
    }
    if ((*count2).second == 1)
    {
      std::cout << "Color: Gray" << std::endl;
    }
    else if ((*count2).second != 1 && (*count2).second != 0)
    {
      std::cout << "Color: White" << std::endl;
    }
    std::cout << "Distance: " << (*dist2).second << std::endl;
    std::cout << "Parent: " << (*par2).second << std::endl;
    std::cout << "--------------------------" << std::endl;
  }
}

// Function that used in printDFS function
void Graph::dfsVisit(int a, std::map<int, color_t>& col, std::map<int, int>& dist, std::map<int, int>& par){
  timer++;
  dist[a] = timer;
  col[a] = Gray;
  for(std::vector<int>::iterator count = vertices[a].begin(); count != vertices[a].end(); ++count){
    if(col[(*count)] == White){
      par[(*count)] = a;
      dfsVisit((*count), col, dist, par);
    }
    if(col[(*count)] == Gray){
      dag = false;
    }
  }
  col[a] = Black;
  timer++;
  finalTime[a] = timer;
}

// Function that performs Depth-First-Search on our graph in order to find
// the shortest path to the node with a specific number
void Graph::printDFS(){
  std::map<int, color_t> color;
  std::map<int, int> par;
  std::map<int, int> dist;
  genGrid(color, dist, par);

  for(std::map<int, std::vector<int>>::iterator count = vertices.begin(); count != vertices.end(); ++count){
    finalTime.insert(std::pair<int, int>((*count).first, std::numeric_limits<int>::max()));
  }

  timer = 0;
  for(std::map<int, std::vector<int>>::iterator count2 = vertices.begin(); count2 != vertices.end(); ++count2){
    if(color[(*count2).first] == White) {
      dfsVisit((*count2).first, color, dist, par);
    }
  }

  std::map<int, color_t>::iterator colorCount = color.begin();
  std::map<int, int>::iterator distCount = dist.begin();
  std::map<int, int>::iterator parCount = par.begin();
  std::map<int, int>::iterator finalCount = finalTime.begin();
  for(int i = 0; colorCount != color.end(); ++colorCount, ++distCount, ++parCount, ++finalCount){
    std::cout << "Vertex: " << (*colorCount).first << std::endl;
    if ((*colorCount).second == 0)
    {
      std::cout << "Color: Black" << std::endl;
    }
    if ((*colorCount).second == 1)
    {
      std::cout << "Color: Gray" << std::endl;
    }
    else if ((*colorCount).second != 1 && (*colorCount).second != 0)
    {
      std::cout << "Color: White" << std::endl;
    }
    std::cout << "Distance: " << (*distCount).second << std::endl;
    std::cout << "Parent: " << (*parCount).second << std::endl;
    std::cout << "--------------------------" << std::endl;
  }
}


// Function that topologically sorts the graph and prints it
void Graph::printTOPO(){
  printDFS();
  // Cannot perform topo sort if graph is not a dag
  if(dag == false){
    std::cout << "Graph is not a DAG, exiting printTOPO function!" << std::endl;
    return;
  }
  std::vector<std::pair<int, int>>vectors;
  for(std::map<int, int>::iterator count = finalTime.begin(); count != finalTime.end(); ++count){
    vectors.push_back(std::pair<int, int>((*count).second, (*count).first));
  }
  std::sort(vectors.begin(), vectors.end());
  std::reverse(vectors.begin(), vectors.end());
  for(std::vector<std::pair<int, int>>::iterator count2 = vectors.begin(); count2 != vectors.end(); ++count2){
      std::cout << "[" << ((*count2).first) << " | " << ((*count2).second) << "], ";
  }
  std::cout << std::endl;
  std::cout << "--------------------------" << std::endl;
}

// Prints scc of graph
void Graph::dfsSCCVisit(int a, std::map<int, color_t>& col){
  col[a] = Gray;
  for(std::vector<int>::iterator count = vertices[a].begin(); count != vertices[a].end(); ++count){
    if(col[(*count)] == White){
      dfsSCCVisit((*count), col);
    }
  }
  col[a] = Black;
  std::cout << a << ", ";
}

// Function that returns the scc of graphs based on their finalTime
void Graph::dfsSCC(std::vector<std::pair<int, int>> vectors){
  std::map<int, color_t> color;
  for(std::vector<std::pair<int, int>>::iterator count = vectors.begin(); count != vectors.end(); ++count){
    color.insert(std::make_pair((*count).second, White));
  }
  std::cout << "SCC:";
  for(std::vector<std::pair<int, int>>::iterator count2 = vectors.begin(); count2 != vectors.end(); ++count2){
    if(color[(*count2).second] == White){
      dfsSCCVisit((*count2).second, color);
    }
  }
}

// Function that prints the strongly connected components in the graph
void Graph::printSCC(){
  printDFS();
  Graph g;
  for(std::map<int, std::vector<int>>::iterator count = vertices.begin(); count != vertices.end(); ++count){
    g.addVertex((*count).first);
  }
  for(std::map<int, std::vector<int>>::iterator count2 = vertices.begin(); count2 != vertices.end(); ++count2){
    for(std::vector<int>::iterator count3 = ((*count2).second.begin()); count3 != ((*count2).second.end()); ++count3){
      g.addEdge((*count3), ((*count2).first));
    }
  }
  std::vector<std::pair<int, int>> vectors;
  for(std::map<int, int>::iterator count4 = finalTime.begin(); count4 != finalTime.end(); ++count4){
    vectors.push_back(std::pair<int, int>((*count4).second, ((*count4).first)));
  }
  std::sort(vectors.begin(), vectors.end());
  std::reverse(vectors.begin(), vectors.end());
  g.dfsSCC(vectors);
}

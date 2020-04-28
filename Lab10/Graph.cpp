#include "Graph.h"

// Function that generates a grid to be used in Breadth-First-Search

void Graph::genGrid(std::map<int, color_t> &col, std::map<int, int> &dist)
{
  std::map<int, std::vector<int>>::iterator count;
  for (count = vertices.begin(); count != vertices.end(); ++count)
  {
    col.insert(std::pair<int, color_t>((*count).first, White));
    dist.insert(std::pair<int, int>((*count).first, std::numeric_limits<int>::max()));
  }
}

// Function that allows a vertex or new "node" to be added into the graph

void Graph::addVertex(int a)
{
  std::map<int, std::vector<int>>::iterator count;
  count = vertices.find(a);
  if (count != vertices.end())
  {
    std::cout << "ERROR: " << a << " already appears in the graph!" << std::endl;
    return;
  }
  std::vector<int> edge;
  vertices.insert(std::pair<int, std::vector<int>>(a, edge));
  std::cout << "Vertex " << a << " is now in the graph!" << std::endl;
}

// Function that allows an edge to be made between two vertices that already exist
// in the graph

void Graph::addEdge(int a, int b)
{
  if (a == b)
  {
    std::cout << "ERROR: Tried to create self edge of (" << a << ", " << b << ")!" << std::endl;
    return;
  }
  std::map<int, std::vector<int>>::iterator count;
  count = vertices.find(a);
  // If vertex a is not found
  if (count == vertices.end())
  {
    std::cout << "Vertex " << a << " was not found in the graph!" << std::endl;
    return;
  }
  count = vertices.find(b);
  // If vertex b is not found
  if (count == vertices.end())
  {
    std::cout << "Vertex " << b << " was not found in the graph!" << std::endl;
    return;
  }
  // If vertices are found
  vertices[a].push_back(b);
  vertices[b].push_back(a);
  std::cout << "Edge (" << a << ", " << b << ") created successfully!" << std::endl;
}

// Function to print the vertex in the graph and the other vertices they
// are connected to

void Graph::print()
{
  for (std::map<int, std::vector<int>>::iterator count = vertices.begin(); count != vertices.end(); ++count)
  {
    std::cout << (*count).first << " is connected to the following vertices: ";
    for (std::vector<int>::iterator vectorCount = (*count).second.begin(); vectorCount != (*count).second.end(); ++vectorCount)
    {
      if (vectorCount == (*count).second.end() - 1)
      {
        std::cout << *vectorCount;
      }
      else
      {
        std::cout << *vectorCount << ", ";
      }
    }
    std::cout << std::endl;
  }
}

// Function that performs Breadth-First-Search on our graph in order to find the
// shortest path to the node with a specific number

void Graph::printBfs(int s)
{
  std::queue<int> que;
  std::map<int, color_t> color;
  std::map<int, int> dist;
  genGrid(color, dist);

  color[s] = Gray;
  dist[s] = 0;

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
        que.push(*count);
      }
      color[temp] = Black;
    }
  }

  std::map<int, color_t>::iterator count2 = color.begin();
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
    std::cout << "--------------------------" << std::endl;
  }
}

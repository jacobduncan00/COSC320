# Expected Format for AdjacencyList.txt

Vertex1: [edge1, edge2, ..., edgeN]
Vertex2: [edge1, edge2, ..., edgeN]
.
.
.
VertexN: [edge1, edge2, ..., edgeN]


# A
My approach to this lab was to understand exactly what was being ask. I sometimes get confused as to the goal of exactly what is being asked however, I took my time to think about the possibilities of how I could solve the cover, cover random, and brute method of printing the edges.

# B
The time complexity is O(|V| + |E|).
This is due to the fact that my algorithms do not need to traverse all the edges in the graph to find if they are covered or not. Brute force time complexity would be O(|E|) + (2^n) I believe because it checks all subsets of n vertices

# C
Worst case for these algorithms would be if a graph has no edges or if every node only had one edge. That would mean that the algorithm would have to traverse every node in order to detect their edges.

# D
These algorithms would be optimal if for every node in the graph, each node is connected to at least on other noded.

# E
The random cover algorithms provides better outcomes as the probability to traverse the graph as needed is higher than that of the normal cover algorithm as random has different starting and end nodes.

# F
My code can always be improved, I'm unsure as to whether the algorithms themselves are ineffcient and have a better method of solving the cover print. 
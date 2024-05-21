## Kruskal's Algorithm Implementation Documentation

### Overview

This project implements Kruskal's algorithm, a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. The program reads an adjacency matrix representing the graph from an input file, applies Kruskal's algorithm to find the MST, and writes the MST to an output file along with the total weight of the MST and the execution time of the algorithm.

### Files

1. **Rahmani_Erfan_Kruskal_Input.cpp**:
   - **Purpose**: Generates a random adjacency matrix representing a graph and writes it to an input file for the Kruskal's algorithm implementation.
   - **Functionality**:
     - Generates random vertex names.
     - Generates a random adjacency matrix with random edge weights.
     - Writes the number of vertices, vertex indices, and adjacency matrix to an input file.

2. **Rahmani_Erfan_Kruskal_PQ_Output.cpp**:
   - **Purpose**: Implements Kruskal's algorithm using a priority queue and writes the resulting MST to an output file.
   - **Functionality**:
     - Reads the adjacency matrix from the input file.
     - Applies Kruskal's algorithm using a priority queue to find the MST.
     - Writes the number of vertices, vertex indices, MST edges, total weight of the MST, and execution time to an output file.

### Implementation Details

#### Rahmani_Erfan_Kruskal_Input.cpp

- **Functions**:
  1. `generateVertexName(int index)`: Generates random vertex names based on the index.
  2. `generateAdjacencyMatrix(int numVertices)`: Generates a random adjacency matrix representing a graph with the given number of vertices.

- **Main Functionality**:
  - Takes input for the number of vertices.
  - Generates random vertex names.
  - Generates a random adjacency matrix.
  - Writes the generated data to an input file.

#### Rahmani_Erfan_Kruskal_PQ_Output.cpp

- **Structs**:
  1. `Edge`: Represents an edge with its weight, source, and destination vertices.
  2. `CompareEdges`: Comparator function for sorting edges in ascending order of weight.

- **Classes**:
  1. `UnionFind`: Implements the union-find data structure for cycle detection.

- **Functions**:
  1. `kruskalMST(...)`: Implements Kruskal's algorithm to find the MST.
  2. `main()`: Reads the input file, applies Kruskal's algorithm, and writes the MST to an output file.

### Execution

1. Compile both source files separately.
2. Execute `Rahmani_Erfan_Kruskal_Input.cpp` to generate the input file.
3. Execute `Rahmani_Erfan_Kruskal_PQ_Output.cpp` to apply Kruskal's algorithm and generate the output file.

### Dependencies

- C++ Standard Library
- Chrono Library (for measuring execution time)

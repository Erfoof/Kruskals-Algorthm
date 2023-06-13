//Program: Rahmani_Erfan_Kruskal_PQ_Output.cpp
//Course: TCP2101 Algorithm Design & Analaysis
//Class: TC1L
//Trimester: 2220
//Member_1 1201102372 | Rahmani Erfan | 1201102372@student.mmu.edu.my | //+60 183120426
//********************************************************************************
//Task Distribution:
// Member 1: Everything
//********************************************************************************



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#include <iomanip>

struct Edge {
    int weight, src, dest;

    Edge(int weight, int src, int dest) : weight(weight), src(src), dest(dest) {}
};

struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) const {
        return a.weight > b.weight;
    }
};

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

void kruskalMST(const std::vector<std::vector<std::string>>& adjacencyMatrix, const std::vector<std::string>& vertexNames, std::ofstream& outputFile) {
    int numVertices = vertexNames.size();
    std::priority_queue<Edge, std::vector<Edge>, CompareEdges> pq;

    // Add all edges to the priority queue
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] != "i") {
                int weight = std::stoi(adjacencyMatrix[i][j]);
                pq.push(Edge(weight, i, j));
            }
        }
    }

    UnionFind uf(numVertices);
    std::vector<Edge> mst;
    int totalWeight = 0;

    // Kruskals Algo.
    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        if (uf.find(currentEdge.src) != uf.find(currentEdge.dest)) {
            uf.unite(currentEdge.src, currentEdge.dest);
            mst.push_back(currentEdge);
            totalWeight += currentEdge.weight;
        }
    }

    // Output the results to the file
    outputFile << numVertices << std::endl;

    outputFile << std::endl;
    for (int i = 0; i < numVertices; i++) {
        outputFile << i << " " << vertexNames[i] << std::endl;
    }

    outputFile << std::endl;
    for (const Edge& edge : mst) {
        outputFile << vertexNames[edge.src] << " " << vertexNames[edge.dest] << " " << edge.weight << std::endl;
    }
    outputFile << "\n";
    outputFile << totalWeight << "\n\n";
}

int main() {
    int outputVertexNum = 0;
    std::cout << "(For File Reading Purposes) \n";
    std::cout << "Number of vertcies? ";
    std::cin >> outputVertexNum;
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream inputFile("kruskalwithoutpq_kruskalwithpq_am_" + std::to_string(outputVertexNum) + "_input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    int numVertices;
    inputFile >> numVertices;

    std::vector<std::string> vertexNames(numVertices);
    for (int i = 0; i < numVertices; i++) {
        int index;
        std::string name;
        inputFile >> index >> name;
        vertexNames[index] = name;
    }

    std::vector<std::vector<std::string>> adjacencyMatrix(numVertices, std::vector<std::string>(numVertices));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();
    /*std::ofstream outputFile("kruskalwithoutpq_kruskalwithpq_am_" + std::to_string(numVertices) + "_input.txt");*/
    std::ofstream outputFile("kruskalwithpq_am_" + std::to_string(numVertices) + "_output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    // Time taken:

    kruskalMST(adjacencyMatrix, vertexNames, outputFile);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    outputFile << std::fixed << std::setprecision(5) << duration.count() << " seconds" << std::endl;

    outputFile.close();

    std::cout << "Compelte!";

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

// Generating a random vertex name
std::string generateVertexName(int index) {
    std::string name;
    while (index >= 0) {
        name.insert(name.begin(), 'A' + (index % 26));
        index /= 26;
        index--;
    }
    return name;
}

// Adjacency matrix generation
std::vector<std::vector<std::string>> generateAdjacencyMatrix(int numVertices) {
    std::vector<std::vector<std::string>> matrix(numVertices, std::vector<std::string>(numVertices));

    std::random_device rd;
    unsigned seed = rd() ^ 1201102372;
    std::mt19937 gen(seed); //Generator Engine
    std::uniform_int_distribution<> dis(0, 1); //To decide whether connection is made or not
    std::uniform_int_distribution<> weightDis(1, 10); // For edge weights


    for (int i = 0; i < numVertices; i++) {
        for (int j = i; j < numVertices; j++) {
            if (i == j) {
                matrix[i][j] = "i";  // Vertex not connected to itself
            }
            else {
                int isConnected = dis(gen);  // deciding whether vertices will be connected or not
                if (isConnected) {
                    int weight = weightDis(gen);  // Random weight from 1 to 10
                    matrix[i][j] = std::to_string(weight);
                    matrix[j][i] = std::to_string(weight);  // Making sure the adjacency matrix is symmetric
                }
                else {
                    matrix[i][j] = "i";
                    matrix[j][i] = "i";
                }
            }
        }
    }

    return matrix;
}

int main() {
    int numVertices;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;

    // Generating the vertex names
    std::vector<std::string> vertexNames;
    for (int i = 0; i < numVertices; i++) {
        std::string name = generateVertexName(i);
        vertexNames.push_back(name);
    }

    // Generating the adjacency matrix
    std::vector<std::vector<std::string>> adjacencyMatrix = generateAdjacencyMatrix(numVertices);

    // Output of the output into a file.
    std::ofstream outputFile("kruskalwithoutpq_kruskalwithpq_am_" + std::to_string(numVertices) + "_input.txt"); //converting numVertices to string

    if (outputFile.is_open()) {
        // Output of the number of vertices
        outputFile << numVertices << std::endl;

        // Output of vertex index and name.
        for (int i = 0; i < numVertices; i++) {
            outputFile << i << " " << vertexNames[i] << std::endl;
        }

        // Output of adjacency matrix
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                outputFile << adjacencyMatrix[i][j] << " ";
            }
            outputFile << std::endl;
        }

        outputFile.close();
        std::cout << "File Generated." << std::endl;
    }
    else {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    return 0;
}

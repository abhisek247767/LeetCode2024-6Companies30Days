/*
QUESTION -- Floyd Warshall Algorithm


DESCRIPTION -- 
The task is to determine the shortest distances between all pairs of vertices in an edge-weighted directed graph. The graph is provided as an adjacency matrix of size n*n, where Matrix[i][j] represents the weight of the edge from vertex i to vertex j. If Matrix[i][j] equals -1, 
it indicates that there is no direct edge between vertices i and j.

The algorithm works by iterating over each node as an intermediate point between every pair of nodes (i and j). The distance between i and j is updated by comparing the current distance and the path that goes through the intermediate node, using the formula:
matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]).

This method also helps to detect negative cycles. If, after running the algorithm, the distance from a node to itself becomes negative, it indicates the presence of a negative cycle. 

TIME COMPLEXITY -- The time complexity of Floyd-Warshall is O(V^3), where V is the number of vertices.


INPUT --
matrix[][] = { {0, 3, -1, 7},
               {8, 0, 2, -1},
               {5, -1, 0, 1},
               {2, -1, -1, 0} }

OUTPUT -- 
0 3 5 6
5 0 2 3
3 6 0 1
2 5 7 0

EXPLANATION -- 
In this example, the final matrix stores the shortest distances between all pairs of nodes. For instance, matrix[0][3] = 6 indicates that the shortest distance from node 0 to node 3 is 6. Similarly, matrix[2][1] = 8 shows the shortest distance from node 2 to node 1.
In general, matrix[i][j] is storing the shortest distance from node i to j.
*/

#include <bits/stdc++.h>
using namespace std;

class Solver {
public:
    void calculateShortestDistance(vector<vector<int>>& m) {
        int size = m.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (m[i][j] == -1) {
                    m[i][j] = 1e9;
                }
                if (i == j) m[i][j] = 0;
            }
        }

        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
                }
            }
        }

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (m[i][j] == 1e9) {
                    m[i][j] = -1;
                }
            }
        }
    }
};

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n));
    
    cout << "Enter the matrix (use -1 for no direct path):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    Solver obj;
    obj.calculateShortestDistance(m);

    cout << "The shortest distances between each pair of vertices are:\n";
    for (auto& row : m) {
        for (auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

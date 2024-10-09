#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& visited, int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's algorithm implementation
void dijkstra(const vector<vector<int>>& graph, int start, int n) {
    vector<int> dist(n, INF);       // Distance from start to each vertex
    vector<bool> visited(n, false); // Visited vertices

    dist[start] = 0; // Distance from the start vertex to itself is 0

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the vertex with the minimum distance value
        int u = minDistance(dist, visited, n);

        // Mark the chosen vertex as visited
        visited[u] = true;

        // Update dist[] of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            // Update dist[v] if there is an edge, and the total weight of the path through u is smaller
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output the shortest distances from the start vertex
    cout << "Vertex \t Distance from Source (" << start << ")" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            cout << i << "\t No path" << endl;
        } else {
            cout << i << "\t " << dist[i] << endl;
        }
    }
}

int main() {
    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    
    cout << "Enter the adjacency matrix (enter 0 if no edge, use a large value for no connection, e.g., 999):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int start;
    

    cout << "Enter the starting vertex: ";
    cin >> start;


    dijkstra(graph, start, n);

    return 0;
}

// Sample Input:
// Enter the number of vertices: 5
// Enter the adjacency matrix (enter 0 if no edge, use a large value for no connection, e.g., 999):
// 0 10 0 30 100
// 10 0 50 0 0
// 0 50 0 20 10
// 30 0 20 0 60
// 100 0 10 60 0
// Enter the starting vertex: 0

// Sample Output:
// Vertex   Distance from Source (0)
// 0        0
// 1        10
// 2        60
// 3        30
// 4        60

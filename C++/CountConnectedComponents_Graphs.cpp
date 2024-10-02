#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    // DFS function to visit all connected nodes
    void dfs(int node, vector<int> adjLs[], vector<int>& vis) {
        vis[node] = 1; // Mark the node as visited
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis); // Recursively visit the connected nodes
            }
        }
    }
    
public:
    // Function to find the number of provinces
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(); // Number of nodes (cities)
        vector<int> adjLs[V]; // Adjacency list representation
        
        // Construct the adjacency list from the given matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i); // Since it's an undirected graph
                }
            }
        }
        
        vector<int> vis(V, 0); // Initialize all nodes as unvisited
        int cnt = 0; // To count the number of connected components (provinces)
        
        // Perform DFS for each unvisited node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++; // Found a new connected component
                dfs(i, adjLs, vis); // Start DFS from this node
            }
        }
        
        return cnt; // Return the number of provinces
    }
};

int main() {
    // Create an instance of the Solution class
    Solution sol;

    // Example input: adjacency matrix representation of city connections
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    // Call the findCircleNum function and store the result
    int result = sol.findCircleNum(isConnected);
    
    // Output the result
    cout << "Number of provinces: " << result << endl;

    return 0;
}

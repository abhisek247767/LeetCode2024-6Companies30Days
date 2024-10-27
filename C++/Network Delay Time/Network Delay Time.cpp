#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Create an adjacency list to represent the graph
        vector<vector<pair<int, int>>> graph(n);
        // Populate the adjacency list with directed edges
        for (const vector<int> &time : times)
        {
            const int u = time[0] - 1;
            const int v = time[1] - 1;
            const int w = time[2];
            graph[u].emplace_back(v, w);
        }
        return dijkstra(graph, k - 1);
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>> &graph, int src)
    {
        // Initialize distance vector with a large value (representing infinity)
        vector<int> dist(graph.size(), INT_MAX);
        // Set distance to the source node as 0
        dist[src] = 0;
        using P = pair<int, int>; // Pair structure to represent (distance, node)
        // Min-heap to store nodes in the order of their distance from the source
        priority_queue<P, vector<P>, greater<>> minHeap;
        minHeap.emplace(dist[src], src);
        while (!minHeap.empty())
        {
            const auto [d, u] = minHeap.top();
            minHeap.pop();
            // Skip processing if a shorter distance has already been found
            if (d > dist[u])
                continue;
            // Update distances for neighboring nodes
            for (const auto &[v, w] : graph[u])
                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    minHeap.emplace(dist[v], v);
                }
        }
        // Get the maximum distance in the dist array
        const int maxDist = *max_element(dist.begin(), dist.end());
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};

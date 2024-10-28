/*
Problem Statement:
743. Network Delay Time

You are given a network of `n` nodes, labeled from `1` to `n`. You are provided with a list of travel times as directed edges,
where `times[i] = (ui, vi, wi)` represents a directed edge from node `ui` to node `vi` with a travel time of `wi`. This means it takes
`wi` units of time for a signal to travel from `ui` to `vi`.

A signal is sent from a starting node `k`. The task is to determine the minimum time needed for all `n` nodes in the network to receive
the signal. If it's impossible for all nodes to receive the signal, return `-1`.

Parameters:
- `times`: A list of directed edges where `times[i] = (ui, vi, wi)` represents:
 - `ui`: Source node
 - `vi`: Destination node
 - `wi`: Travel time from ui to vi
- `n`: Total number of nodes in the network (labeled from 1 to n)
- `k`: Starting node from which the signal is sent

Return:
- Minimum time required for all nodes to receive the signal
- `-1` if any node is unreachable

Examples:
1. Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
   Output: 2
   Explanation: Signal starts at node 2, reaches nodes 1 and 3 in 1 unit time, then reaches node 4 in 2 units time.

2. Input: times = [[1,2,1]], n = 2, k = 1
   Output: 1
   Explanation: Signal starts at node 1 and reaches node 2 in 1 unit time.

3. Input: times = [[1,2,1]], n = 2, k = 2
   Output: -1
   Explanation: Signal starts at node 2 but can't reach node 1.
*/

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

        // Call the Dijkstra function to calculate the minimum time
        return dijkstra(graph, k - 1);
    }

private:
    /*
    Algorithm: Dijkstra's Algorithm for Shortest Path

    Steps:
    1. Initialize a distance vector 'dist' of size n with all elements set to INT_MAX to represent
       initially unreachable nodes. Set the distance of the source node 'k' to 0.
    2. Use a min-heap priority queue 'minHeap' to store nodes in the order of their current shortest distance from the source node.
       Initialize the heap with the source node.
    3. While there are nodes in the heap:
        a. Pop the node with the minimum distance 'd' and node 'u' from the heap.
        b. If 'd' is greater than the current distance in 'dist[u]', skip further processing for this node.
        c. For each neighboring node 'v' with edge weight 'w' from 'u' to 'v', check if the new distance 'd + w' is smaller than the
           current distance in 'dist[v]'. If it is, update 'dist[v]' and add 'v' with its updated distance to the minHeap.
    4. After processing all nodes, check the maximum value in 'dist'. If the maximum is still INT_MAX, it means at least one node
       was unreachable, so return -1. Otherwise, return the maximum distance as the minimum time required for all nodes to receive the signal.
    */

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

        // Process the graph using Dijkstra's algorithm
        while (!minHeap.empty())
        {
            const auto [d, u] = minHeap.top();
            minHeap.pop();

            // Skip processing if a shorter distance has already been found
            if (d > dist[u])
                continue;

            // Update distances for neighboring nodes
            for (const auto &[v, w] : graph[u])
            {
                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    minHeap.emplace(dist[v], v);
                }
            }
        }

        // Get the maximum distance in the dist array
        const int maxDist = *max_element(dist.begin(), dist.end());

        // Return the result based on whether all nodes were reachable
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};

/*
You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 

Example 1:

Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

Output: 5

Explanation:



Use the path 0 → 1 (cost 3).
At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
Total cost is 3 + 2 = 5.
Example 2:

Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

Output: 3

Explanation:

No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
Total cost is 1 + 1 + 1 = 3.
 

Constraints:

2 <= n <= 5 * 104
1 <= edges.length <= 105
edges[i] = [ui, vi, wi]
0 <= ui, vi <= n - 1
1 <= wi <= 1000
  */
// Time Complexity: O(E log V) where E is the number of edges and V is the number of vertices (nodes).
// Space Complexity: O(V + E), where V is the number of nodes and E is the number of edges.
// Problem Link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.first != b.first)
            return a.first > b.first; // Compare by cost first
        return (a.second > b.second); // If costs are same, compare by node
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // Step 1: Create an adjacency list where each node points to its neighbors and respective costs
        vector<vector<pair<int, int>>> arr(n);
        for(auto x: edges) {
            arr[x[0]].push_back({x[1], x[2]}); // Edge from x[0] to x[1] with cost x[2]
            arr[x[1]].push_back({x[0], 2*x[2]}); // Reverse edge with doubled cost
        }
        
        // Step 2: Priority Queue for Dijkstra's Algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        
        // Step 3: Distance array, initialized with a large value
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        
        // Step 4: Push the start node into the priority queue
        pq.push({0, 0});
        
        // Step 5: Dijkstra's Algorithm
        while(!pq.empty()) {
            int d = pq.top().first; // Current distance
            int b = pq.top().second; // Current node
            pq.pop();
            
            // Explore all the neighbors of node 'b'
            for(int i = 0; i < arr[b].size(); i++) {
                int nextNode = arr[b][i].first;
                int edgeCost = arr[b][i].second;
                
                // Relax the edge if a shorter path is found
                if(dist[nextNode] > edgeCost + d) {
                    dist[nextNode] = edgeCost + d;
                    pq.push({d + edgeCost, nextNode});
                }
            }
        }
        
        // Step 6: Return the final result
        if(dist[n-1] == 1e9) {
            return -1; // No path found
        }
        return dist[n-1]; // Minimum cost to reach node n-1
    }
};

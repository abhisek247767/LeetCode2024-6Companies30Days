#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Define a struct for representing edges in the graph
struct Edge {
    int to;
    int weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

// Define a custom comparison function for the priority queue
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

// Dijkstra's algorithm for finding shortest paths
vector<int> dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distances(n, INF);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().first;
        int u_dist = pq.top().second;
        pq.pop();

        if (u_dist != distances[u]) continue;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (distances[u] + w < distances[v]) {
                distances[v] = distances[u] + w;
                pq.push({v, distances[v]});
            }
        }
    }

    return distances;
}

int main() {
    int n = 5;
    vector<vector<Edge>> graph(n);

    // Add edges to the graph
    graph[0].push_back(Edge(1, 1));
    graph[0].push_back(Edge(2, 4));
    graph[1].push_back(Edge(2, 2));
    graph[1].push_back(Edge(3, 5));
    graph[2].push_back(Edge(3, 1));
    graph[3].push_back(Edge(4, 1));

    int start_node = 0;
    vector<int> shortest_distances = dijkstra(graph, start_node);

    cout << "Shortest distances from node " << start_node << ":\n";
    for (int i = 0; i < n; ++i) {
        cout << "To node " << i << ": " << shortest_distances[i] << endl;
    }

    return 0;
}

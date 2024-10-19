#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;

class RoadNetwork {
public:
    int V;
    vector<set<pair<int, int>>> adj;

    RoadNetwork(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addRoad(int u, int v, int time) {
        auto it = adj[u].find({v, time});
        if (it != adj[u].end()) adj[u].erase(it);
        adj[u].insert({v, time});

        it = adj[v].find({u, time});
        if (it != adj[v].end()) adj[v].erase(it);
        adj[v].insert({u, time});
    }

    void removeRoad(int u, int v) {
        for (auto it = adj[u].begin(); it != adj[u].end();) {
            if (it->first == v) it = adj[u].erase(it);
            else ++it;
        }
        for (auto it = adj[v].begin(); it != adj[v].end();) {
            if (it->first == u) it = adj[v].erase(it);
            else ++it;
        }
    }

    int shortestPath(int src, int dest) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            for (auto &edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};

int main() {
    int intersections = 6;
    RoadNetwork city(intersections);

    city.addRoad(0, 1, 10);
    city.addRoad(0, 2, 5);
    city.addRoad(1, 2, 2);
    city.addRoad(1, 3, 1);
    city.addRoad(2, 3, 9);
    city.addRoad(3, 4, 4);
    city.addRoad(4, 5, 6);

    cout << city.shortestPath(0, 4) << endl;

    city.addRoad(2, 4, 7);
    cout << city.shortestPath(0, 4) << endl;

    city.removeRoad(1, 3);
    cout << city.shortestPath(0, 4) << endl;

    city.removeRoad(3, 4);
    cout << city.shortestPath(0, 5) << endl;

    return 0;
}

import heapq

class Graph:
    def __init__(self):
        self.adj = {}

    def add_edge(self, u, v, weight):
        if u not in self.adj: self.adj[u] = []
        if v not in self.adj: self.adj[v] = []
        self.adj[u].append((v, weight))

def dijkstra(graph, start_node):
    distances = {node: float('inf') for node in graph.adj}
    distances[start_node] = 0
    
    pq = [(0, start_node)]  # (distance, node)

    while pq:
        current_distance, current_node = heapq.heappop(pq)

        if current_distance > distances[current_node]:
            continue

        if current_node in graph.adj:
            for neighbor, weight in graph.adj[current_node]:
                distance = current_distance + weight

                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))
    
    return distances

# --- Example: Road Network ---

# City A, B, C, D, E, F with travel times (weights)
city_graph = Graph()
city_graph.add_edge('A', 'B', 7)
city_graph.add_edge('A', 'C', 9)
city_graph.add_edge('A', 'F', 14)
city_graph.add_edge('B', 'C', 10)
city_graph.add_edge('B', 'D', 15)
city_graph.add_edge('C', 'D', 11)
city_graph.add_edge('C', 'F', 2)
city_graph.add_edge('D', 'E', 6)
city_graph.add_edge('E', 'F', 9)

start_city = 'A'
shortest_times = dijkstra(city_graph, start_city)

print(f"Shortest travel times starting from {start_city}:")
for city, time in sorted(shortest_times.items()):
    if time != float('inf'):
        print(f"  To {city}: {time} minutes")
    else:
        print(f"  To {city}: Unreachable")

#include <iostream>
#include <vector>
using namespace std;

bool dfsDirected(
    vector<vector<int>>& graph,
    int curr,
    vector<bool>& visited,
    vector<bool>& onPath
) {
    visited[curr] = true;
    onPath[curr] = true;

    for (int next : graph[curr]) {
        if (!visited[next]) {
            if (dfsDirected(graph, next, visited, onPath))
                return true;
        }
        else if (onPath[next]) {
            return true;
        }
    }

    onPath[curr] = false;
    return false;
}

bool hasCycleDirected(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<bool> onPath(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsDirected(graph, i, visited, onPath))
                return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> graph(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cout << (hasCycleDirected(graph) ? "YES\n" : "NO\n");
}

#include <iostream>
#include <vector>
using namespace std;

bool dfsUndirected(
    vector<vector<int>>& graph,
    int curr,
    vector<bool>& visited,
    int parent
) {
    visited[curr] = true;

    for (int next : graph[curr]) {
        if (!visited[next]) {
            if (dfsUndirected(graph, next, visited, curr))
                return true;
        }
        else if (next != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycleUndirected(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsUndirected(graph, i, visited, -1))
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
        graph[v].push_back(u);
    }

    cout << (hasCycleUndirected(graph) ? "YES\n" : "NO\n");
}

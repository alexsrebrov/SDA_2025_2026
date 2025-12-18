#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void bfs(vector<unordered_set<int>>& graph, int start, int n, vector<int>& dist) {
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    int level = 1;
    int visitedCount = 1;

    while (!q.empty() && visitedCount < n) {

        int layerSize = q.size();
        for (int j = 0; j < layerSize; j++) {

            if (visitedCount == n)
                break;

            int curr = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (graph[curr].find(i) == graph[curr].end() && !visited[i]) {
                    visited[i] = true;
                    dist[i] = level;
                    q.push(i);
                    visitedCount++;
                }
            }
        }
        level++;
    }
}

void processQuery() {
    int n, m;
    cin >> n >> m;

    vector<unordered_set<int>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].insert(v);
        graph[v].insert(u);
    }

    int start;
    cin >> start;
    start--;

    vector<int> dist(n, -1);
    bfs(graph, start, n, dist);

    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        cout << dist[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        processQuery();
    }

    return 0;
}


class Solution {
public:
    static constexpr int RED   = 0;
    static constexpr int BLUE  = 1;
    static constexpr int START = -1;

    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);
        return graph;
    }

    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges
    ) {
        auto redGraph  = buildGraph(n, redEdges);
        auto blueGraph = buildGraph(n, blueEdges);

        vector<bool> visitedRed(n, false);
        vector<bool> visitedBlue(n, false);
        vector<int> dist(n, -1);

        queue<pair<int,int>> q;
        q.push({0, START});

        int level = 0;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto [node, lastColor] = q.front();
                q.pop();

                if (dist[node] == -1)
                    dist[node] = level;

                // Take RED edge if last was not RED
                if (lastColor != RED) {
                    for (int& next : redGraph[node]) {
                        if (!visitedRed[next]) {
                            visitedRed[next] = true;
                            q.push({next, RED});
                        }
                    }
                }

                // Take BLUE edge if last was not BLUE
                if (lastColor != BLUE) {
                    for (int& next : blueGraph[node]) {
                        if (!visitedBlue[next]) {
                            visitedBlue[next] = true;
                            q.push({next, BLUE});
                        }
                    }
                }
            }

            level++;
        }

        return dist;
    }
};

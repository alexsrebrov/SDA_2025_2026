#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Graph {
    int numVertices;
    bool directed;
    vector<int> *adjList;

public:
    Graph(int V, bool directed) : numVertices(V),
    adjList(new vector<int>[V]), directed(directed) {}

    void addEdge(int v, int w) {
        if (!directed) {
            adjList[w].push_back(v);
        }
        adjList[v].push_back(w);
    }
    vector<int> adj(int v) {
        return adjList[v];
    }
    int vertices() {
        return numVertices;
    }
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;
        Graph g(n, 0);
        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin>>x>>y;
            g.addEdge(x, y);
        }
        vector<bool> visited(n, 0);
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                queue<int> q;
                q.push(i);
                while(!q.empty())
                {
                    int curr = q.front();
                    for(int& el : g.adj(curr))
                    {
                        if(!visited[el])
                        {
                            visited[el] = 1;
                            q.push(el);
                        }
                    }
                    q.pop();
                }
                count++;
            }
        }
        cout << count << ' ';
    }
    return 0;
}

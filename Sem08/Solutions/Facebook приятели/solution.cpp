#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, vector<int>> adj;
unordered_map<int, bool> visited;

void dfs(int v, int& ctr)
{
    visited[v] = true;
    ctr++;
    for(int& el : adj[v])
    {
        if(!visited[el])
            dfs(el, ctr);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int v, e, k;
    cin >> v >> e >> k;
    int from, to;
    for(int i = 0; i < e; i++)
    {
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    int cnt = 0, ctr = 0;
    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            dfs(i, ctr);
            if(ctr % k == 0)
                cnt++;
            ctr = 0;
        }
    }
    cout << cnt;
    return 0;
}

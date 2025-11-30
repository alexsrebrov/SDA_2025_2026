#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> m;
    int minLen = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        auto p = m.insert({v[i], i});
        if(!p.second)
            minLen = min(minLen, i - m[v[i]]);
    }
    cout << minLen;
    return 0;
}

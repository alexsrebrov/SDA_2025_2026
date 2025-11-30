#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    int s;
    int counter = 0;
    for(int i = 0; i < n; i++)
    {
        cnt[v[i]]++;
        cin >> s;
        if(!cnt[s])
            counter++;
        else
            cnt[s]--;
    }
    cout << counter;
    return 0;
}

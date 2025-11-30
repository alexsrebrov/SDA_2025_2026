#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());
    int num;
    for(int i = 0; i < m; i++)
    {
        cin >> num;
        auto it = lower_bound(v.begin(), v.end(), num);
        int res = it - v.begin();
        cout << res <<" "; 
    }
    return 0;
}



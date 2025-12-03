#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> fp;
map<int, int> lp;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    int num;
    for(int i = 0; i < k; i++)
    {
        cin >> num;
        auto lb = lower_bound(v.begin(), v.end(), num);
        if(*lb == num)
        {
            auto ub = upper_bound(v.begin(), v.end(), num);
            int idx1 = lb - v.begin();
            int idx2 = ub - v.begin() - 1;
            cout << idx1 << " " << idx2 << endl;
        }
        else
            cout << lb - v.begin() << endl;
    }
    
    return 0;
}

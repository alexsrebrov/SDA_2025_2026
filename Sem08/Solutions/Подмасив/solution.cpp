#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
constexpr int MAX_SIZE = 1e6 + 1;
vector<bool> v(MAX_SIZE);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    queue<int> q;
    int n;
    cin >> n;
    int num;
    size_t maxLen = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        if(v[num])
        {
            while(!q.empty() && q.front() != num)
            {
                v[q.front()] = false;
                q.pop();
            }
            while(!q.empty() && q.front() == num)
                q.pop();
        }
        q.push(num);
        v[num] = true;
        maxLen = max(maxLen, q.size());
    }
    cout << maxLen;
    return 0;
}


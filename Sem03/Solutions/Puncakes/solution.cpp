#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool check(long long time, long long k, vector<long long>& speed)
{
    long long cnt = 0;
    for(long long i = 0; i < speed.size(); i++)
        cnt += time / speed[i];
    
    return cnt >= k;
}

long long binarySearch(long long left, long long right, long long k, vector<long long>& speed)
{
    long long res;
    while(left <= right)
    {
        long long mid = left + (right - left) / 2;
        
        if(check(mid, k, speed))
        {
            res = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;        
    }
    return res;
}

int main() {
    long long k, n;
    cin >> k >> n;
    vector<long long> v(n);
    long long maxSpeed = INT_MAX, minSpeed = INT_MIN;
    for(long long i = 0; i < n; i++)
    {
        cin >> v[i];
        maxSpeed = min(v[i], maxSpeed);
        minSpeed = max(v[i], minSpeed);
    }
    long long left = (k / n) * maxSpeed;
    long long right = (k / n + 1) * minSpeed;
    long long res = binarySearch(left, right, k, v);
    cout << res;
    return 0;
}

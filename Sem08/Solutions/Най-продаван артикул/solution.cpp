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
map<int, int> ctr;
map<int, int> maxAtTime;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int index, time;
    int currMax = -1;
    int minTime = INT_MAX, maxTime = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        cin >> index >> time;
        ctr[index]++;
        if(ctr[index] >= ctr[currMax])
        {
            currMax = index;
        }
        maxAtTime[time] = currMax;
        minTime = min(minTime, time);
        maxTime = max(maxTime, time);
    }
    
    int req;
    cin >> req;
    int t;
    for(int i = 0; i < req; i++)
    {
        cin >> t;
        if(t < minTime)
        {
            cout << -1 << endl;
        }
        else if(t >= maxTime)
        {
            cout << maxAtTime[maxTime] << endl;
        }
        else
        {
            auto it = maxAtTime.lower_bound(t);
            if((*it).first > t)
                it--;
            cout << (*it).second << endl;
        }
    }
}

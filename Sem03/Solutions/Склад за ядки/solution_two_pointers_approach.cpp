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

struct Box 
{
    int w;
    int index;
    
    Box(int w, int index) : w(w), index(index) {}
};

bool operator<(const Box& lhs, const Box& rhs)
{
    return lhs.w < rhs.w;
}

void handleRequest()
{
    int weight;
    cin >> weight;
    
    int n;
    cin >> n;
    
    vector<Box> v;
    
    int num;
    
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back({num, i + 1});
    }
    
    sort(v.begin(), v.end());
    
    size_t start = 0, end = v.size() - 1;
    
    while(start < end) {
        long long sum = v[start].w + v[end].w;
        
        if(sum == weight) {
            break;
        } else if(sum < weight) {
            start++;
        } else {
            end--;
        }
    }
    
    cout << min(v[start].index, v[end].index) << " " << max(v[start].index, v[end].index) << endl;    
}

using namespace std;
int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        handleRequest();
    }
    return 0;
}

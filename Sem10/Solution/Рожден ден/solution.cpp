#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
constexpr int MAX_SIZE = 500001;

struct fr 
{
    int arr;
    int dep;
    int idx;
    
    fr(int arr, int dep, int idx) : arr(arr), dep(dep), idx(idx) {}
    
    bool operator<(const fr& other)
    {
        if(arr == other.arr)
            return dep < other.dep;
        
        return arr < other.arr;
    }
};

unordered_map<int, int> idx_chair;

int main() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue<int, vector<int>, greater<int>> chairs;
    
    for(int i = 0; i < MAX_SIZE; i++)
        chairs.push(i);
    
    int n;
    cin >> n;
    vector<fr> v;
    int arr, l;
    for(int i = 0; i < n; i++)
    {
        cin >> arr >> l;
        v.push_back({arr, l, i});
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < n; i++)
    {
        int currArrival = v[i].arr;
        while(!pq.empty() && pq.top().first <= currArrival)
        {
            chairs.push(pq.top().second);
            pq.pop();
        }
        
        idx_chair[v[i].idx] = chairs.top();
        chairs.pop();
        pq.push({v[i].dep, idx_chair[v[i].idx]});
    }
    
    int index;
    cin >> index;
    cout << idx_chair[index];
    return 0;
}

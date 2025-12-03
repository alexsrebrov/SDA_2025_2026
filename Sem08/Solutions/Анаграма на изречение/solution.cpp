#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isAnagram()
{
    string word;
    int p, q;
    cin >> p >> q;
    unordered_map<string, long long> ctr;
    for(int i = 0; i < p; i++)
    {
        cin >> word;
        ctr[word]++;
    }
    for(int i = 0; i < q; i++)
    {
        cin >> word;
        ctr[word]--;
    }
    
    for(auto it = ctr.begin(); it != ctr.end(); it++)
    {
        if((*it).second < 0)
            return false;
    }
    
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        if(isAnagram())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

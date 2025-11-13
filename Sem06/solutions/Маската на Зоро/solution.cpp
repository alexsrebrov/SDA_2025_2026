#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void push_masks(set<int>& s, int n)
{
    for(int i = 0; i <= n; i++)
    {
        if((n | i) == n)
            s.insert(i);
    }
}

int main() {
    set<int> s;
    int n; 
    std::cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        push_masks(s, num);
    }
    
    std::cout << s.size();
    return 0;
}
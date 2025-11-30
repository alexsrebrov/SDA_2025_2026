#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unordered_map<string, int> m;
    string s;
    while(cin >> s)
    {
        m[s]++;
    }

    for(auto it = m.begin(); it != m.end(); it++){
        if(it->second == 1)
            cout << it->first << endl;

    }

    return 0;
}

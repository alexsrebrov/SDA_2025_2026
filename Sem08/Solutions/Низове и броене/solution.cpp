#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        unordered_map<int,int> countFreq;
        for (auto &p : freq) countFreq[p.second]++;

        if (countFreq.size() == 1) {
            if(countFreq.begin()->second == 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";

            continue;
        }

        if (countFreq.size() > 2) {
            cout << 0 << "\n";
            continue;
        }

        auto it = countFreq.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;

        if (f1 > f2) {
            swap(f1,f2);
            swap(c1,c2);
        }
        
        bool ok = false;

        if (f1 == 1 && c1 == 1)
            ok = true;

        if (f2 == f1 + 1 && c2 == 1)
            ok = true;

        cout << (ok ? 1 : 0) << "\n";
    }
    return 0;
}

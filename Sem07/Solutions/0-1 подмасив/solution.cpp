#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) a[i] = -1;
    }

    unordered_map<int, int> firstIndex;
    int prefix = 0;
    int best = 0;

    for (int i = 0; i < n; i++) {
        prefix += a[i];

        if (prefix == 0) {
            best = max(best, i + 1);
        }

        if (firstIndex.count(prefix)) {
            best = max(best, i - firstIndex[prefix]);
        } else {
            firstIndex[prefix] = i;
        }
    }

    cout << best << endl;
    return 0;
}

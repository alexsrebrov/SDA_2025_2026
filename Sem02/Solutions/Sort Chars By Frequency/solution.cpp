class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> freq(256);
        for (int c = 0; c < 256; ++c) freq[c] = {0, (char)c};

        for (char& c : s) freq[c].first++;

        sort(freq.begin(), freq.end(),
             [](const auto& a, const auto& b) {
                 return a.first > b.first;
             });

        string res;
        res.reserve(s.size());
        for (auto [cnt, ch] : freq) {
            if (cnt == 0) break;   
            res.append(cnt, ch);
        }
        return res;
    }
};

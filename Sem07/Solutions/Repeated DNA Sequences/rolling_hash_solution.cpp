class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10) return {};

        unordered_map<char, int> mp = {
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
        };

        unordered_set<int> seen;    
        unordered_set<int> repeated; 

        int hash = 0;
        int mask = (1 << 20) - 1; 

        vector<string> result;

        for (int i = 0; i < n; i++) {
            hash = ((hash << 2) | mp[s[i]]) & mask;

            if (i >= 9) { 
                if (!seen.count(hash)) {
                    seen.insert(hash);
                } else if (!repeated.count(hash)) {
                    repeated.insert(hash);
                    result.push_back(s.substr(i - 9, 10));
                }
            }
        }

        return result;
    }
};

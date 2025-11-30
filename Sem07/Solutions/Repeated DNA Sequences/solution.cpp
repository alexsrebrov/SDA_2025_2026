class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> subseq;

        int n = s.size();

        for (int i = 0; i <= n - 10; i++) {
            string sub = s.substr(i, 10);
            subseq[sub]++;
        }
        
        vector<string> res;

        for (auto& ss : subseq) {
            if (ss.second > 1) {
                res.push_back(ss.first);
            }
        }
        return res;
    }
};

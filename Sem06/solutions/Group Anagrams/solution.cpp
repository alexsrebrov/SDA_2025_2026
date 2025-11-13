class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<string, vector<string>> mp;

       for(auto& str : strs)
       {
            string cp = str;
            sort(cp.begin(), cp.end());
            mp[cp].push_back(str);
       } 

       vector<vector<string>> res;

       for(auto it = mp.begin(); it != mp.end(); ++it)
       {
            res.push_back(it->second);
       }

       return res;
    }
};
class Solution {
    bool check(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] == s[j]) { 
                i++; 
                j--; 
            }
            else {
                return check(s, i + 1, j) || check(s, i, j - 1);
            }
        }
        return true;
    }
};

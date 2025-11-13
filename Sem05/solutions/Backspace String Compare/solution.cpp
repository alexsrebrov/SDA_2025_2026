class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1, st2;
        for(const char& ch: s) {
            if(ch == '#') {
                if(!st1.empty()) st1.pop();
            } else {
                st1.push(ch);
            }
        }

        for(char& ch: t) {
            if(ch == '#') {
                if(!st2.empty()) st2.pop();
            } else {
                st2.push(ch);
            }
        }

        if(st1.size() != st2.size()) return false;

        while(!st1.empty()) {
            if(st1.top() != st2.top()) return false;

            st1.pop();
            st2.pop();
        }

        return true;
    }
};
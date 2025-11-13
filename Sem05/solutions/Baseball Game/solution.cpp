class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        
        for(const string& op : ops) {
            if(op == "C") {
                s.pop();
            }
            else if(op == "D") {
                s.push(s.top() * 2);
            }
            else if(op == "+") {
                int value1 = s.top();
                s.pop();
                int value2 = s.top();
                s.push(value1);
                s.push(value1 + value2);
            }
            else {
                s.push(stoi(op)); //stoi() converts string into integer 
            }
        }

        int res = 0;

        while(s.size()) {
            res += s.top();
            s.pop();
        }

        return res;
    }
};
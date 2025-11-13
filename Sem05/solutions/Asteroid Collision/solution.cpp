class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int curr : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && curr < 0) {
                if (abs(st.top()) < abs(curr)) {
                    st.pop(); // top explodes, continue checking
                } else if (abs(st.top()) == abs(curr)) {
                    st.pop(); // both explode
                    destroyed = true;
                    break;
                } else {
                    destroyed = true; // current asteroid explodes
                    break;
                }
            }

            if (!destroyed) st.push(curr);
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        
        return result;
    }
};
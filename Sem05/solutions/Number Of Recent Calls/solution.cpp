/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        
        while (head) {
            vals.push_back(head->val);
            head = head->next;
        }
        
        int n = vals.size();
        vector<int> res(n, 0);
        stack<int> st; 
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && vals[i] > vals[st.top()]) {
                res[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }
        
        return res;
    }
};

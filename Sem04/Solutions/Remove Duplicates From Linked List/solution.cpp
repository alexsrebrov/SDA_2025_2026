class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;

        while (head && head->next) {
            if (head->val == head->next->val) {
                ListNode* curr = head->next;
                head->next = head->next->next;
                delete curr;
            } else {
                head = head->next;
            }
        }

        return res;        
    }
};

class Solution {
public:
    size_t getLen(ListNode* head)
    {
        if(!head)
            return 0;
        
        size_t cnt = 0;
        while(head)
        {
            cnt++;
            head = head->next;
        }

        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return nullptr;

        size_t sizeA = getLen(headA);
        size_t sizeB = getLen(headB);

        while(sizeA > sizeB)
        {
            headA = headA->next;
            sizeA--;
        }

        while(sizeA < sizeB)
        {
            headB = headB->next;
            sizeB--;
        }

        while(headA && headB && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;        
    }
};

bool has_cycle(SinglyLinkedListNode* head) {
    using sllNode = SinglyLinkedListNode;
    
    if (!head || !head->next) return false;
    sllNode* slow = head;
    sllNode* fast = head->next;

    while (fast && fast->next) {
        if (slow == fast) return true;
        
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

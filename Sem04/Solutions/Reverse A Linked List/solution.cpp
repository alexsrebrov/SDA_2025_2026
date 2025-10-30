SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
    using sllNode = SinglyLinkedListNode;
    
    sllNode* prev = nullptr;
    
    while(llist){
        sllNode* next = llist->next;
        llist->next = prev;
        prev = llist;
        llist = next;
    } 
    
    return prev;
}

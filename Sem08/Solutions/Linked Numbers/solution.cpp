#include <bits/stdc++.h>
using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList{
    public:
    Node *head, *tail;
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    ~LinkedList(){
        Node* temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void add(int value){
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void print(){
        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data;
            curr = curr->next;
        }
    }
    void reverse() {
        Node* newHead = tail;
        Node* newTail = head;
        Node* prev = nullptr;
        Node* curr = head;
        while(curr != nullptr) 
        { 
            Node* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        head = newHead;
        tail = newTail;
    }
};

void solve(LinkedList& num1, LinkedList& num2){
    bool oneInMind = false;
    Node* head1 = num1.head;
    Node* head2 = num2.head;
    LinkedList res;
    while(head1 != nullptr && head2 != nullptr)
    {
        int resNum = head1->data + head2->data;
        if(oneInMind){
            oneInMind = false;
            resNum++;
        }
        if(resNum > 9)
        {
            oneInMind = true;
            resNum %= 10;
        }
        
        res.add(resNum);
        
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    int toAdd = 0;
    while(head1 != nullptr)
    {
        if(oneInMind)
        {
            toAdd = 1;
            oneInMind = false;
        }
        else
            toAdd = 0;
        res.add(head1 -> data + toAdd);
        head1 = head1 -> next;
    }
    while(head2 != nullptr)
    {
        if(oneInMind)
        {
            toAdd = 1;
            oneInMind = false;
        }
        else
            toAdd = 0;
        res.add(head2-> data + toAdd);
        head2 = head2-> next;
    }
    if(oneInMind)
        res.add(1);
    res.reverse();
    res.print();
    
}

int main(){
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for(int i = 0 ; i < size1 ; i++){
        int digit;
        cin >> digit;
        num1.add(digit);
    }
    cin >> size2;
    for(int i = 0 ; i < size2 ; i++){
        int digit;
        cin >> digit;
        num2.add(digit);
    }
    
    solve(num1, num2);
}

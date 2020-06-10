/*
Design your implementation of the linked list. 
You can choose to use the singly linked list or the doubly linked list. 
A node in a singly linked list should have two attributes: val and next. 
val is the value of the current node, and next is a pointer/reference to the next node. 
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. 
Assume all nodes in the linked list are 0-indexed.
*/

struct ListNode{
public:
    int val;
    ListNode* next;
    ListNode()=defualt;
    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList():
        head(nullptr),
        tail(nullptr),
        size(0)
    {
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index<0||index>size-1){
            return -1;
        }
        int i = 0; 
        ListNode* temp = head;
        while(i++<index){
           temp = temp->next; 
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        //empty linked list
        if(head == nullptr){
            head = new ListNode(val);
            tail = head;
        }
        else{
            ListNode* temp = new ListNode(val);
            temp->next = head;
            head = temp;
        }
        size++;
    }
    
    /** Append a ListNode of value val to the last element of the linked list. */
    void addAtTail(int val) {
        //empty linked list
        if(tail == nullptr){
            head = new ListNode(val);
            tail = head;
        }
        else{
            ListNode*temp=new ListNode(val);
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    /** Add a ListNode of value val before the index-th ListNode in the linked list. If index equals to the length of linked list, the ListNode will be appended to the end of linked list. If index is greater than the length, the ListNode will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>size||index<0){
            return;
        }
            
        int i = 0;
        ListNode* temp = head;
        //add at head
        if(index == 0){
            auto x = new ListNode(val);
            x->next = head;
            head = x;
            if(tail == nullptr){
                tail=head;
            }
            size++;
            return;
        }
        
        while(i++<index-1){
            temp = temp->next;
        }
            
        auto newNode = temp->next;
        temp->next = new ListNode(val);
        temp->next->next = newNode;
        //check tail update
        if(index == size)
            tail = temp->next;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size||index<0){
            return;
        }
            
        int i = 0;
        ListNode* temp = head;
        //delete at head
        if(index == 0){
            auto p = head;
            head = head->next;
            if(size==1)
                tail=head;
            size--;
            delete(p);
            return;
        }
        
        while(i++<index-1){
           temp = temp->next; 
        }
            
        auto oldNode = temp->next;
        temp->next = oldNode->next;
        delete(oldNode);
        if(index == size-1)
            tail=temp;
        size--;
    }
    
    private:
    ListNode* head;
    ListNode* tail;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
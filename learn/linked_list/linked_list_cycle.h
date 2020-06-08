

#include "linked_list.h"
#include <unordered_set>

class Solution {
public:
    /*
    Given a linked list, determine if it has a cycle in it.

    To represent a cycle in the given linked list, 
    we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. 
    If pos is -1, then there is no cycle in the linked list.
    */
    bool hasCycle(ListNode *head) {
        //use hash set to record
        std::unordered_set<ListNode*> hashSet;
        
        while(head != nullptr){
            if(hashSet.find(head) != hashSet.end() ){
                return true;
            }else{
                hashSet.insert(head);
                
            }
            head = head->next;
        }
        return false;
    }

    /*
    Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
    */
    //use  Floyd’s Cycle-Finding Algorithm
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        
        while(fastPtr != nullptr && fastPtr->next != nullptr){
            //fast pointer will travel twice as fast 
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
            if(slowPtr == fastPtr){
                break;
            }
        }
        
        //check for valid ptr and find out the start index of cycle
        if(slowPtr == fastPtr && slowPtr != nullptr && slowPtr->next != nullptr){
            slowPtr = head;
            while(slowPtr != fastPtr){
                slowPtr = slowPtr->next;
                fastPtr = fastPtr->next;
            }
            return slowPtr;
        }
        return NULL;
        
    }

    /*
    Write a program to find the node at which the intersection of two singly linked lists begins.
    */
    //using two pointer technique
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cntA = 0, cntB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        
        //count the length of each linked list
        //separate operation
        while(ptrA != NULL) {
            cntA++;
            ptrA = ptrA->next;
        }
        while(ptrB != NULL) {
            cntB++;
            ptrB = ptrB->next;
        }
        
        //redirect:
        //When pApA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.);
        //similarly when pBpB reaches the end of a list, redirect it the head of A.
        ListNode * _short = cntA > cntB ? headB : headA;
        ListNode * _long = cntA > cntB ? headA : headB;
        for(int i = 0; i < abs(cntA - cntB); i++) {
            _long = _long->next;
        }
        while(_short != _long) {
            _short = _short->next;
            _long = _long->next;
        }
        return _short;
    }
};
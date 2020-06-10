#include <iostream>
#include "../linked_list/linked_list.h"


class MyHashSet {
public:
    //Use array+Linkedlist for hash table
    
    //overload new operator
    void* operator new(size_t size) 
    {
        void* ptr = malloc(size);
        std::cout<<"allocate size: "<<size<< " at memory: "<<ptr << std::endl; 

        return ptr;
    }

    void operator delete(void* ptr){
        //cout<<"free memory at : "<< ptr<<endl;
        free(ptr); 
    }
    
    /** Initialize your data structure here. */
    MyHashSet() {
        m_hashTable = new ListNode[m_hashTableCapacity];///<An array of linked list node 
         
    }
    
    
    void add(int key) {
        //check if element already exists
        if(contains(key)){
            std::cout<<"key already exists"<<std::endl;
            return;
        }
        
        //check for rehash
        if (m_length/m_hashTableCapacity > 10){//rehash condition
            rehash();
        } 
            
        //add key to the start of the bucket
        int hashTableIndex = hashFunc(key);
        ListNode* firstNode = m_hashTable[hashTableIndex].next;
        ListNode* newNode = new ListNode(key);
        newNode->next = firstNode;
        m_hashTable[hashTableIndex].next = newNode;
        ++m_length;
    }
    
    void remove(int key) {
        int hashTableIndex = hashFunc(key);
        //check for next node value
        for(ListNode* cur = &m_hashTable[hashTableIndex]; cur->next != NULL; cur = cur->next){
            if(cur->next->val == key){
                ListNode* removeNode = cur->next;
                cur->next = removeNode->next;
                delete removeNode;
                --m_length;
                std::cout<<"element removed"<<std::endl;
                return;
            }
        }
        std::cout<<"element not found\n";
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashTableIndex = hashFunc(key);
        for (ListNode* cur = m_hashTable[hashTableIndex].next; cur != NULL; cur = cur->next)
        {
            if (cur->val == key)
            {
                return true;
            }
        }
        return false;
        }
    
private:
    //hash function: return index of the bucket to insert
    inline int hashFunc(int key){
        return key % m_hashTableCapacity;     
    }
    
    //rehash the table
    void rehash(){
        std::cout<<"Rehash Required"<<std::endl;
        
        int oldCapacity = m_hashTableCapacity;
        int newCapacity = 2 * oldCapacity;
        ListNode* newHashTable = new ListNode[newCapacity];
        
        //recalculate hash function and rearrange hash table
        for (int i = 0; i < oldCapacity; i++){
            ListNode* temp = NULL;
            for(ListNode* oldCur = m_hashTable[i].next; oldCur != NULL; oldCur = temp){
                temp = oldCur->next; //store the address of next as we will modify oldCur
                int newHashTableIndex = oldCur->val % newCapacity;
                 oldCur->next = newHashTable[newHashTableIndex].next;
                //the node should be pointed by the newHTbl next refernce to 
                newHashTable[newHashTableIndex].next = oldCur;
            }
        }
        //delete old hashtable
        //delete m_hashTable;

        //update to the new HashTable
        m_hashTableCapacity = newCapacity;
        m_hashTable = newHashTable;
        
        std::cout<<"Rehash Finished"<<std::endl;
    }
    
private:
	int m_length = 0;
    int m_hashTableCapacity = 10;
	ListNode* m_hashTable;
        
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
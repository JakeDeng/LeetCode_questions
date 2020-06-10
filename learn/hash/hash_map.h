#include <iostream>

struct MapNode {
    int key;
    int val;
    MapNode *next;
    MapNode() {next = nullptr;}
    MapNode(int x, int y): key(x), val(y), next(nullptr) {}
    void updateValue (int value){
        val = value;
    }
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        m_hashTable = new MapNode[m_hashTableCapacity];///<An array of linked Map node 
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        //check for rehash
        if (m_length/m_hashTableCapacity > 10){//rehash condition
            rehash();
        } 
            
        //add key-value pair the bucket
        int hashTableIndex = hashFunc(key);
        //loop through each Mapnode to check key
        for(MapNode* cur = m_hashTable[hashTableIndex].next; cur != NULL ; cur = cur->next ){
            //check if key has existed
            //std::cout<<"cur->key: "<<cur->key<< std::endl;
            if(cur->key == key){
                cur->updateValue(value);
                return;
            }
        }
        
        //add new node to the map
        MapNode* firstNode = m_hashTable[hashTableIndex].next;
        MapNode* newNode = new MapNode(key, value);
        newNode->next = firstNode;
        m_hashTable[hashTableIndex].next = newNode;
        ++m_length;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        //calculate hash table index
        int hashTableIndex = hashFunc(key);
        //loop through each Mapnode to check key
        for(MapNode* cur = m_hashTable[hashTableIndex].next; cur != NULL ; cur = cur->next ){
            //check if key has existed
            if(cur->key == key){
                return cur->val;
            }
        }
        std::cout<<"key doesn't exist"<<std::endl;
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        //calculate hash table index
        int hashTableIndex = hashFunc(key);
        //check for next node value
        for(MapNode* cur = &m_hashTable[hashTableIndex]; cur->next != NULL; cur = cur->next){
            if(cur->next->key == key){
                MapNode* removeNode = cur->next;
                cur->next = removeNode->next;
                delete removeNode;
                --m_length;
                std::cout<<"element removed"<<std::endl;
                return;
            }
        }
        std::cout<<"element not found\n";
    }
    
private:
    //hash function: return index of the bucket to insert
    inline int hashFunc(int key){
        return key % m_hashTableCapacity;     
    }
    
    void rehash(){
        //rehash function
    }
private:
    int m_length = 0;
    int m_hashTableCapacity = 10;
	MapNode* m_hashTable;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
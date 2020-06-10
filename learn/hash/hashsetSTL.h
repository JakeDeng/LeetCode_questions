#include <vector>
#include <unordered_set>

/*
 * Template for using hash set to find duplicates.
 */
template<typename T>
bool findDuplicates(vector<T>& keys) {
    // Replace Type with actual type of your key
    unordered_set<T> hashset;
    for (T key : keys) {
        if (hashset.count(key) > 0) {
            return true;
        }
        hashset.insert(key);
    }
    return false;
}

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hashset;
    for (int num : nums) {
        if (hashset.count(num) > 0) {
            return true;
        }
        hashset.insert(num);
    }
    return false;
}

int singleNumber(vector<int>& keys) {
    unordered_set<int> hashset;
    for (int key : keys) {
        hashset.insert(key);
    }
    
    for (int key : keys) {
        if (hashset.count(key) == 1){
            return key;
        }
    }
    return -1;
}
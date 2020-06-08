#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

//two-pass hash table
class Solution_1 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //return vector
        std::vector<int> return_vector;
        //map <index, value>
        std::multimap<int, int> map;
        
        //putting input vextor into a map
        for (unsigned int i = 0; i < nums.size(); ++i){
            map.insert(std::make_pair(nums[i], i));
        }
        
        //iterate through the map using an iterator
        //it is an iterator
        for(auto it=map.begin(); it!=map.end(); ++it){
            int remain = target - it->first;
           
            auto found = map.find(remain);
            //if found and elements are only used once
            if(found != map.end() && found != it)
            {
                //put indice into vector and return
                return_vector = {found->second, it->second};
                std::sort(return_vector.begin(), return_vector.end());
                return return_vector;
            }
        }
        return return_vector;
    }
};

//one-pass hash table
class Solution_2 {
public:
    //one pass hash table
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        //hash table
        std::map<int, int> map;
        std::vector<int> re_v;
        
        for (int i = 0; i < nums.size(); ++i){
            //find as inserting value
            //count search the element in the container, if found then return 1
            if(map.count(target - nums[i])){
                re_v = {i ,map[target - nums[i]]};
                std::sort(re_v.begin(), re_v.end());
                return re_v;
            }
            
            //if not found, insert value
            map[nums[i]] = i;
        }
        return {};
    }
};
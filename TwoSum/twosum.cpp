//Brute Force
class Solution_1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
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


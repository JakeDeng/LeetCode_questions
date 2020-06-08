#include <vector>

//twp pass
class Solution_1 {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& A) {
        // even array
        std::vector<int> even;
        std::vector<int> odd;
        
        for(unsigned int i=0; i<A.size(); ++i){
            if(A[i]%2 == 0){
                //even
                even.push_back(A[i]);
            }
            else{
                odd.push_back(A[i]);
            }
        }
        //combine
        even.insert(even.end(), odd.begin(),odd.end());
        return even;
        
    }
};

//in-place:quick sort
class Solution_2 {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& A) {
        //create two pointers
        int i = 0;
        int j = A.size()-1;
        //merge into the middle
        while(i < j){
            //swap
            if(A[i]%2 ==1 && A[j]%2 ==0){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            if(A[i]%2 == 0 ) i++;
            if(A[j]%2 == 1 ) j--;
            
        }
        return A;
    }
};
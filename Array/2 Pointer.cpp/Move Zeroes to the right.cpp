#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        // brute force would be just make a new array, first adding non zero element and filling the array up
        // with zeros to the size of nums. TC -> O(n) but SC -> O(n)

        // Algo that does this work : In place. 
        // 2 pointers just like we did in unique elements first in sorted array.
        // the qn here is non zero elements first, put zero in rest

        int i = 0;

        for(int j = 0; j < nums.size(); j++){

        // If the current element is not 0, then we need to append it just in front of last non 0 element we 
        // found.
            if(nums[j] != 0){
                nums[i] = nums[j]; // ith element would already have been dealt with so no loss of data.
                i++;
            }
        }

        // After we have finished processing new elements, all the non-zero elements are already at beginning of 
        // array. We just need to fill remaining array with 0's.
        for(int k = i; k < nums.size(); k++){
            nums[k] = 0;
        }

    }
};
#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Moore's voting algo

        int count = 1;
        int candidate = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(count == 0)
                candidate = nums[i];
            if(nums[i] == candidate)
                count++;
            else    
                count--;
        }

        // is the candidate a majority element, check ?
        count = 0;
        for( int i = 0; i < nums.size(); i++){
            if(nums[i] == candidate)
                count ++;
        }
        if(count > nums.size()/2)
            return candidate;
        else
            return -1;
    }
};
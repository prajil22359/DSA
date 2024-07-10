#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:

    // Think like Kadane: or even odd subarray length -> the condition is different thats all.

    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0){
            return 0;
        }

        int count = 1;
        int maxi = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){

            // skip duplicates
            if(nums[i] == nums[i-1]) continue;

            if((nums[i] == nums[i - 1] + 1)){
                count++;
            }
            else{
                count = 1;
            }
            maxi = max(count, maxi); 
        }
    
    return maxi;
    }
};
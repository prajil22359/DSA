#include <iostream>
using namespace std;
#include <vector>

// Finding maximum subarray sum : its sum and the subarray itself

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        // brute force sab subarray check in O(n^2).

        // kadane's algo O(n)
        
        int sum = 0;
        int maxi = nums[0]; // if it can't have empty sub array.
        int ansStart = -1;
        int ansEnd = -1;
        int start = 0;

        for(int i = 0; i < nums.size(); i++){
            // element lidai jane, negative bhae reset garne else lidai jane.
            if(sum < 0){
                sum = 0;
                start = i;
            }
            sum += nums[i];
            maxi = max(sum, maxi);

            // if the sub array from 'start' updates the maximum, update our ans subarray. 
            if(maxi == sum){
                ansStart = start;
                ansEnd = i;
            }
        }
        return maxi;
        // ansStart, ansEnd --> is the subArray that yielded the maximum sum subarray.
    }
};
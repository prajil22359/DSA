#include <iostream>
using namespace std;
#include <vector>

// jump1 jastai ho bas yesma finding the least jump needed to reach.
// least find garda sabse tada ko index jaha bata jump handa target pugnu paryo.
// so looking for i from 0 to target - 1, and simply counting the jumps,
// as each recursion call is a jump.

int solve(vector<int>& nums, int target){

    if(target == 0){
        return 0;
    }

    for(int i = 0; i < target; i++){
        if(i + nums[i] >= target){
            return 1 + solve(nums, i);
        }
    }
    return 0;
}

int jump(vector<int>& nums) {
    if(nums.size() == 1)    
        return 0;

    return solve(nums, nums.size() - 1);
}
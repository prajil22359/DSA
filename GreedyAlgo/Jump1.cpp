// the qn needs to know if starting from index 0, I can reach index n-1 or not.
// so how I thought of the soln is :
// how do I reach the index n-1, from somewhere behind, so lets check if I can get there from somewhere
// behind -> if i + nums[i] >= target. The target initially is n-1. 
// the qn doesnot end, still we need to know if we can even reach this i from 0. so its recursion from 
// there, i being the new target.

// alik soch ayo ki what if we can reach n-1 from i and cant reach i from 0, but there is other index j<i
// that can reach n-1 and is also reachable from 0. As we are looking just from the first index we found
// the jump to target possible, wont this algo miss somewhere? 
// -> the ans I guess is No. Though its possible that some j < i, can reach n-1, but its not true that
// j can be reached from 0 and not from i. as i can just fall back to j, and we are said j is reachable
// from 0, and if j can reach n-1, it can for sure reach i. All in all, it should work.


#include <iostream>
using namespace std;
#include <vector>

    bool solve(vector<int>& nums, int target){

        if(target == 0){
            return true;
        }

        for(int i = target - 1; i >= 0; i--){
            if(i + nums[i] >= target){
                return solve(nums, i);
            }
        }
        return false;

    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)    
            return true;

        if(nums[0] == 0)
            return false;

        return solve(nums, nums.size() - 1);
    }
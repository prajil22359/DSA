#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int index = -1;

        // step1: finding the element that is lesser than it right.
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        // edge case : when its ever increasing, no critical point so its the largest permutation, 
        // in that case print the smallest one.
        if(index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // step2: find the just greater element
        for(int i = n-1; i > index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }

        // step3: sort the right of index in increasing order, but its already sorted to decreasing
        // so just reverse
        reverse(nums.begin() + index + 1, nums.end());

    }
};
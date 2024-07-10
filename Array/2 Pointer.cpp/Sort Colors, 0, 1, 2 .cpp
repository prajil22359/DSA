#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    //0, 1, 2 bhako array ho, sort garnu cha inplace without using sort fn. DNF Algo bhanera chinincha

    // COUNTING APPROACH
    // just count 0s and 2s in the array, and update the nums array, placing the counted 0s
    // from left and counted 2s from right, rest fill with 1.

    void sortColorsByCounting(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // count of 0s
        int j = 0; // count fo 2s

        for(int k = 0; k < nums.size(); k++){
            if(nums[k] == 0)
                i++;
            else if(nums[k] == 2)
                j++;
        }

        // now just place 0s from left according to its count i
        for(int k = 0; k < i; k++)
            nums[k] = 0;

        // similarly placing 2 from right according to its count j
        for(int k = n-j; k < n; k++)
            nums[k] = 2;
        
        // filling the rest of array with 1.
        for(int k = i; k < n-j; k++)
            nums[k] = 1;
    }

    // 2 pointer approach, DNF algo bhanera famous
    // array lai 4 regions ma divide garne using 3 pointers. low ko left ma 0,
    // low dekhi 1 start huncha, mid dekhi high - 1 samma unknown region, ani high dekhi right end 
    // samma 2. Starting ma sab unknown nai huncha, hamile yo algo chalaera unknown region sakauchau
    // so the loop ends as long as mid <= high. equals to is important

    void dnfSortAlgo(vector<int> &nums){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = 0;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid] == 1){
                mid++;
            }
        }
    }

};
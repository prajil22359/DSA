#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// Rotate the matrix right by d, d can be greater than size of array.

class Solution {
public:

    void rotateOnebyOne(vector<int> & nums){
        int temp = nums[nums.size()-1];
        for(int i = nums.size() - 1; i > 0; i--){
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }

    void rotate(vector<int>& nums, int k) {

            // O(NK), could not pass.
            // while(k > 0){
            //     rotateOnebyOne(nums);
            //     k--;
            // }

            // right rotate
            k = k % nums.size(); // yeh sochne mein ek ghanta lag gaya. rotation 360 == 720 == ..
            reverse(nums.begin(), nums.end()); // 0 to n-1
            reverse(nums.begin(), nums.begin()+k); // 0 to d-1
            reverse(nums.begin()+k, nums.end()); // d-1 to 0

            // left rotate
            // reverse(nums.begin(), nums.begin()+k); // 0 to d-1
            // reverse(nums.begin()+k, nums.end());// d to n-1
            // reverse(nums.begin(), nums.end());// 0 to n-1
    }
};
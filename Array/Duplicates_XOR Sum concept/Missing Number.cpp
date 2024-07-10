#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        // brute force ke hunthyo:  jun jun ayo tyaslai tick lagaudai jane, 
        // ani last ma herne kun chahi aena. MAP use garihal. nlogn

        // map<int, int> dict;

        // for(auto i : nums){
        //     dict[i] = 1;
        // }      

        // for(int i = 0; i <= nums.size(); i++){
        //     if(dict[i] != 1)
        //         return i;
        // }
        // return -1;


        // optimized O(n) algo using sum formula
        // int n = nums.size();
        // int sum = n * (n+1)/2;

        // for(auto i : nums){
        //     sum -= i;
        // }
        // return sum;

        // optimized XOR technique
        // intuition behind bit manipulation solution:
        // it is given the numbers are unique and between 0 to n, this has to be a hint.
        // -> the xors of all numbers from 0 to n if done twice will be equal to zero ->
        // since one number is missing in nums, the xor of all numbers of nums ^ the xor of
        // all numbers from 0 to n will be equal to the missing number.

        int n = nums.size();
        int ans = 0;

        for( int i = 0; i <= n; i++){
            ans = ans ^ i;
        }

        for(auto i : nums){
            ans = ans ^ i;
        }
        return ans;
    }
};
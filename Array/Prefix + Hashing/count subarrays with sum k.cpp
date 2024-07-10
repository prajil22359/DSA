#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map> 

class Solution {
public:

    // brute force : sabai subarrays nikalera.
    // longest ma gareko jastai prefix sum + hashing, but here we count them

    // count garnu cha bhane, index rakhera ta faida chaina, so here hami tyo sum kati ota index ma
    // cha bhanne count store garau.

    // 0 ko case handle ?

    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> prefixSumMap; // <prefixSum, index ko count> 

        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){

            sum += nums[i]; 
            if(sum == k){
                count++;
            }

            int target = sum - k;

            if(prefixSumMap.find(target) != prefixSumMap.end()){
                count = count + prefixSumMap[target];
            }
            if(prefixSumMap.find(sum) == prefixSumMap.end()){
                prefixSumMap[sum] = 1;
            }
            else{ // if already.
                prefixSumMap[sum]++;
            }
        }
        return count;
    }
};
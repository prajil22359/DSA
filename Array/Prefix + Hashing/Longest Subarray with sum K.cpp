
// optimized for array with positive negatives and zero


#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map> 

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        
        // hashmap plus prefix sum.
        unordered_map<int, int> map1; // <prefixSum, index>
        
        int sum = 0;
        int maxi = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
                        if(sum == k){
                maxi = max (maxi, i+1);
            }
            
            
            int target = sum - k;
            
            if(map1.find(target) != map1.end()){
                maxi = max (maxi, i - (map1[target] + 1) + 1);
            }
            
            if(map1.find(sum) == map1.end()){
                map1[sum] = i;
            }
        }
        return maxi;
    } 

};
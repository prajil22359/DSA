#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // precomputing left max and right max for each index.
        vector<int> leftMax(n, -1);
        leftMax[0] = 0;

        vector<int> rightMax(n, -1);
        rightMax[n-1] = 0;

        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        // accumulating the individual trapped water. 
        int totalWater = 0;
        for(int i = 0; i < n; i++){
            int waterAtBarI = min(rightMax[i], leftMax[i]) - height[i];
            if(waterAtBarI > 0){
                totalWater += waterAtBarI;
            }
        }
        return totalWater;
    }
};
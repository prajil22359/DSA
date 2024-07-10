#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                maxi = max(maxi, count);
                count = 0;
            }
            else    
                count += 1;
        }
        // last ma yadi consecutive ones thiyo bhane maxi update gareko chaina so.
        return max(maxi, count);
    }
};
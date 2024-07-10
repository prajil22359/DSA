#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    // her dherai feel ta airaha chaina, tara yesko part 1, n/2 bhanda besi kai concept le huncha re.
    // there can be atmost 2 majority element when we consider majority at > n/3. so 2 candidates

    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int candidate1 = -1;
        int candidate2 = -1;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < n; i++){

            if(count1 == 0 && candidate2 != nums[i]){
                candidate1 = nums[i];
            }

            if(count2 == 0 && candidate1 != nums[i]){
                candidate2 = nums[i];
            }

            if(nums[i] == candidate1){
                count1++;
            }
            else if(nums[i] == candidate2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        // is the candidate a majority ?
        count1 = 0;
        count2 = 0;
        for(auto i : nums){
            if(i == candidate1){
                count1++;
            }
            else if(i == candidate2){
                count2++;
            }
        }
        
        vector<int> ans;
        if(count1 > n/3){
            ans.push_back(candidate1);
        }
        if(count2 > n/3){
            ans.push_back(candidate2);
        }
        return ans;
    }
};
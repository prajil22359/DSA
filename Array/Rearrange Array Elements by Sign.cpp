#include <iostream>
using namespace std;
#include <vector>

// qn says: array lai rearrange gar, yesma n/2 positive, n/2 negative elements chan, 
// alternately rakhnu cha positive negative lai, starting from positive, with the relative order of 
// positives or negatives among themselves maintained.

// It CANT be done in SC -> O(1) use brute force simply.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        // ith index for putting positive values, jth for negative values.

        // as said the first element should be positive, so any positive will go in ith index.
        int i = 0; 
        int j = 1;
        vector <int> ans(nums.size(), -1); 
        // initialize garnu parcha, so that i can replace push_back ma order jancha, 
        // you would not be able to put in the right index

        for(int k = 0; k < nums.size(); k++){
            if(nums[k] > 0){
                // positive
                ans[i] = nums[k];
                i = i + 2; 
            }
            else{
                ans[j] = nums[k];
                j = j + 2; 
            }
        }  
        return ans; 
    }
};
#include <iostream>
using namespace std;
#include <vector>


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // index and element are same, so use vector visited array, not set.


        vector<bool> visited(nums.size() + 1, 0);

        for (auto num: nums) {
            if (!visited[num]) {
                visited[num] = true;
            } 
            else {
                return num;
            }
        }

        return -1;
    }
};
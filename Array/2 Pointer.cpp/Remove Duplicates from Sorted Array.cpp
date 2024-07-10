#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

class Solution {
public:

    // 2 pointer logic ho : yadi element different cha bhane tyaslai i + 1 th index ma store garidine.
    // i samma ko array consists of unique elements.

    // yo kasari garna sakiraha chau kinaki array sorted cha, so there is only chance of the ith element to 
    // come after i being duplicate, i bhanda agadi ko elements haru aune chance nabhaera it works,
    // else sab sanga compare garnu parthyo.
    
    int removeDuplicates(vector<int>& nums) {
        // pahilo element ta unique nai ho.
        int i = 0;
        // second element bata check garne
        for (int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};
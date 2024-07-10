#include <iostream>
using namespace std;
#include <vector>

bool check(vector<int>& nums) {
    // sorted in non decreasing check garna lai just traverse once and see if it has decreased its not sorted
    // so we can return false. However, the array could be rotated so, there can be atmost one decrease
    // but then till the end of array it should be non decreasing, and also arr[0] should not be less than
    // arr[n-1] -> eg herera bujh, sorted condition continuation ko lagi ho.

    // eg: 123456789 -> rotate bhaera : 789123456 -> right rotate , 456789123 -> left rotate

    int count = 0;
    for (int i = 1; i < nums.size(); i++){
        if(nums[i] < nums[i-1]){
            count ++;
        }
    }
    // rotation hoga to bhi bas ek baar ke liye decrease kar sakta he
    if(count > 1){
        return false;
    }

    // count == 1 bhaneko ek thau ma matra decrease garyo however in that case also if first element is 
    // less than last element, it doesnot satisfy any left right rotation, so false
    else if(count == 1 && nums[0] < nums[nums.size()-1])
        return false;

    return true;
}
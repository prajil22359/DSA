
// euta array deko cha, sabai elements lai + ya - halera concatenate garera expression banaune,
// return the distinct ways where that expression would evaluate to a target.

// sum = 0, euta variable initiate garne. sabai elements linu cha, so subset formation, evaluate only
// when index == nums.size(). Ani yesma duita choice add, ya subtract it from sum.

#include<iostream>
using namespace std;
#include<vector>

int solve(vector<int> &nums, int target, int value, int index,  vector<vector<int>> &dp){

    if(value == target && index == nums.size()){
        return 1;
    }

    if(index >= nums.size()){
        return 0;
    }

    if(dp[index][value + 20000]!=-1){
        return dp[index][value + 20000];
    }
        
    // add
    int added = solve(nums, target, value + nums[index], index+1, dp);
    int subtracted = solve(nums, target, value - nums[index], index+1, dp);

    return dp[index][value + 20000] = added + subtracted;

}


int findTargetSumWays(vector<int>& nums, int target) {

    // dp lagcha, index i pachi kati ways chan value == target hune, save garera rakhda good. 

    vector<vector<int>> dp(nums.size()+1, vector<int> (40001, -1));
    // acc to constraints, value cant be more than 20000. So offset 20000 chahiyo, thus array size 40000+1.

    // arko tarika pahilai maxPossible value nikalne sab lai add operator diyera. and use that for offset.
    // int maxPossibleValue = 0;
    // for(auto i : nums){
    //     maxPossibleValue += i; 
    // }
    // vector<vector<int>> dp(nums.size()+1, vector<int> (maxPossibeValue + 1, -1));

    return solve(nums, target, 0, 0, dp);
}
                                        // MUST READ

// thacha yo qn exactly partition_with_given_difference sanga exactly match garcha.
// how? her yaha pani kehi element lai add garchau ta kehi lai subtract garchau, haina ra.
// add gareko lai s1. subtract gareko elements ko sum s2. bhane hamro expression club garda s1 - s2 = d
// hunu parne subsets count garna bhaneko ta ho. jasko lagi hami tyahi algebra s1- s2 = d, s1 + s2 = sumofall.
// thus s1 = (sumofall + d) /2 yo target ko subset khojchau, jati payo tyahi ans.
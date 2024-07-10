// qn is to partition such that s1 - s2 = diff 
// However we also have s1 + s2 = sum of array.
// So solving this two equations, the qn boils down to the count of subsets
// with target sum = (sum of array + diff) /2 . if thats odd, count = 0 easy,
// else will need to find out.


#include <iostream>
using namespace std;
#include <vector>


int solve(vector<int> &nums, int target, int index, vector<vector<int>> &dp){
    // the task is to count subsets with target sum exactly as given

    // base case
    // since 0 ni chan so need to check till last, as need fulfill bhae ni inko include kiya jasakta he
    if(target == 0 & index == nums.size()){
        return 1;
    }

//////// IMPORTANT --> sum == 0 wala case sabse top ma lekhna jaroori cha. kina bhane yadi last index
//////////////  wala lai include garera sum == 0 huncha bhane next index ko call ma matrai thahuncha.
//////////  yadi tyaha index out of bound bhanera pahilai return 0 garyi bhane sum 0 wala case chutcha.


    if(index >= nums.size()){
        return 0;
    }

    if(target<0){
        return 0;
    }

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    // take
    int take = solve(nums, target - nums[index], index+1, dp) % 1000000007;

    // not take
    int notTake = solve(nums, target - 0, index+1, dp) % 1000000007;

    return dp[index][target] = (take + notTake) % 1000000007;
}

int countPartitions(int n, int d, vector<int>& arr){

    int sum = 0;
    for(auto i: arr){
        sum += i;
    }

    if((sum + d) & 1 ){
        return 0;
    }
    
    int target = (sum + d) /2;

    vector<vector<int>> dp(arr.size()+1, vector<int> (target+1, -1));

    return solve(arr, target, 0, dp);
}
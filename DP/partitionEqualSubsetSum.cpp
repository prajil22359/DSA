// qn sajilo cha --> given array lai duita subset ma partition garne such that both their sum is equal
// how to solve --> sum nikalne, sum odd bhae, no way for equal partition given all integers.
// even ko case ma ke garne ta : kunai euta esto subset nikalyo that has sum = sum/2, then bacheko
// element will form the other equal partition. So qn boils down to see if there can be made a subset
// with sum equals to sum/2. Subset banauna ta tyahi take notTake startegy.
// kunai ni take ya notTake le true return gare, return true. 
// recurring sub problems hunchan sum ra index repeat hunchan.

// s1 - s2 = 0;
// s1 + s2 = sum of array.
// s1 = sum of array / 2.

#include <iostream>
using namespace std;
#include <vector>


bool solve(vector<int> &nums, int sum, int index, vector<vector<int>> &dp){
    // the task is to find if there exists a subset with sum exactly as given

    // base case
    if(sum == 0){
        return true;
    }

//////// IMPORTANT --> sum == 0 wala case sabse top ma lekhna jaroori cha. kina bhane yadi last index
//////////////  wala lai include garera sum == 0 huncha bhane next index ko call ma matrai thahuncha.
//////////  yadi tyaha index out of bound bhanera pahilai return 0 garyi bhane sum 0 wala case chutcha.


    if(index == nums.size()){
        return false;
    }

    if(sum<0){
        return false;
    }

    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }

    // take
    bool take = solve(nums, sum - nums[index], index+1, dp);

    // not take
    bool notTake = solve(nums, sum - 0, index+1, dp);

    return dp[index][sum] = take or notTake;
}

bool canPartition(vector<int>& nums) {

    int sum = 0;
    for(auto i: nums){
        sum += i;
    }

    vector<vector<int>> dp(nums.size()+1, vector<int> (sum+1, -1));

    if((sum & 1) == false){ // even cha bhane matra check gar

    // ALERT bitwise ma equality operator ko precednce huncha, so not putting brackets always
    // led the ans as false.

        return solve(nums, sum/2, 0, dp);
    }
    else{ // odd sum is always false
        return false;
    }
}

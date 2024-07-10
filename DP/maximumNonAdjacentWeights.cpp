// house robber I is also the same qn.
// base case bata visualize garne kosis gar, euta weight matrai bhako bhae ke, duita huda ke,
// ith huda ke ma depend gardai cha .. recursion kasari lagyo sochne.

// sabse sajilo subset banako tarika le bujh, given array bata given condition bata maximum sum
// wala subset banaunucha. 0 to n jane ho take, not Take gari with the given conditions.


#include <iostream> 
using namespace std;
#include <vector>

int funcRec(vector<int> &nums, int index){
    if(index==0){
        return nums[0];
    }
    if(index<0){
        return 0;
    }
    int include=nums[index]+funcRec(nums,index-2);
    int exclude=funcRec(nums, index-1);
    return max(include,exclude);
}

int funcMemo(vector<int> &nums, int index, int dp[]){
    if(index==0){
        return nums[0];
    }
    if(index<0){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int include=nums[index]+funcMemo(nums,index-2,dp);
    int exclude=funcMemo(nums, index-1,dp);
    return dp[index]=max(include,exclude);
}

int funcTab(vector<int> &nums){
    int dp[nums.size()];
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);
    for (int i = 2; i < nums.size(); i++) {
        int include = nums[i]+dp[i-2];
        int exclude = dp[i- 1];
        dp[i]=max(include,exclude);
    }
    return dp[nums.size()-1];
}
// space can be optimized...

int maximumNonAdjacentSum(vector<int> &nums){
    // return funcRec(nums,nums.size()-1);
    int dp[nums.size()];
    for(int i=0;i<nums.size();i++){
        dp[i]=-1;
    }
    // return funcMemo(nums,nums.size()-1,dp);
    return funcTab(nums);

}

#include<iostream>
using namespace std;
#include<vector>

// logic --> see it's very similar to the maximum sum of non adjacent weights. just the thing is its not
// linear. so here 0th element -> the first and n-1th -> the last are also adjacent. 
// so if you see this way, we can trim it down to two linear street problems. In one we take 0 to n-2,
// and in the other from 1 to n-1. This way, the first and last will never be together. Case 1 and 2 
// will suffice even in case they dont occur in our ans, cause even in any of the case there will be
// the notTake situation considered too. Our required ans will be the maximum from either of the cases.

long long int solve(vector<int> &valueInHouse, int start, int end, vector<long long int> &dp){

    // base case
    if (start > end){
        return 0;
    }

    if(dp[start]!=-1){
        return dp[start];
    }

    //take
    long long int take = valueInHouse[start] + solve(valueInHouse, start + 2, end, dp);
    long long int notTake = 0 + solve(valueInHouse, start + 1, end, dp); 

    return dp[start] = max(take, notTake);
}

long long int houseRobber(vector<int>& valueInHouse)
{   
    int n = valueInHouse.size(); 

    // edge case
    if(n==1){
        return valueInHouse[0];
    }

    // 1D dp, since only start is changing
    vector<long long int> dp1(n+1, -1);
    long long int case1 = solve(valueInHouse, 0, n-2, dp1);

    vector<long long int> dp2(n+1, -1);
    long long int case2 = solve(valueInHouse, 1, n-1, dp2);
    return max(case1, case2);
}

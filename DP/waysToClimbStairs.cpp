// ways to climb the nth stair? you are going to reach nth stair taking 1 step from n-1th stair 
// or 2 steps from n-2th stair. So just adding those ways. Simple memoization lagaya he,
// only if the recursion gets it to the 0th stair, its a valid way. when k gets negative its invalid way,
// so return 0. if neither, recursion continues.
// Also since k can get negative dp ma index k halda out of bounds jane darr. 
// So need to keep the memoization step below the base case.

#include<iostream>
using namespace std;
#include<vector>

int solve(int k, vector<int> &dp){

    //base case
    if (k==0){
        return 1;
    }
    else if (k<0){
        return 0;
    }
    
    if(dp[k]!=-1){
        return dp[k];
    }

    return dp[k] = solve(k-1, dp) + solve(k-2, dp);
}

int climbStairs(int n) {
    // the particular subproblem that solves the problem
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}
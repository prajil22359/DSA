#include <iostream>
using namespace std;
#include <vector>

// simple qn ho, recursion herdai dekhincha. dp ni lagihalcha 
// overlapping subproblems cause amount same bhaihalcha.

int solve(vector<int> &coins, int amount, vector<int> &dp){

    //base case
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return 1e9;
    }

    if(dp[amount]!=-1){
        return dp[amount];
    }

    int count = 1e9;
    for(auto i : coins){
        if(amount - i >= 0){
            int ans = 1 + solve(coins, amount - i, dp);
            count = min(count, ans);
        }
    }
    return dp[amount] = count;
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, -1);

    int ans = solve(coins, amount, dp);
    if(ans == 1e9){
        return -1;
    }
    else{
        return ans;
    }
}


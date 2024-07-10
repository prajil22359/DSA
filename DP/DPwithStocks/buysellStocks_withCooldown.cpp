#include <iostream>
using namespace std;
#include <vector>

// same qn to part2, you can do any number of transactions, the difference is after you sell
// there is now a cooldown period where you cant buy, i.e. you cant buy the very next day.

// buy pachi canBuy should still be toggled to 1. saying you cant buy but sell/hold.
// but sell pachi canBuy should be off for atleast one more day.
// how we implement is just skip the next index, let the canBuy be toggled to 1, but just skip
// the next day, so you cant buy

// so a little change to our soln to part 2,


int solve(vector<int> &prices, int index, int canBuy, vector<vector<int>> &dp){
        
    if(index >= prices.size()){
        return 0;
    }

    if(dp[index][canBuy]!=-1){
        return dp[index][canBuy];
    }

    int profit = 0;

    // buy
    if(canBuy == 1){
        int buy = - prices[index] + solve(prices, index+1, 0, dp);
        int hold = solve(prices, index+1, canBuy, dp);
        profit = max(buy, hold);
    }
    else{
    //sell

        int sell = prices[index] + solve(prices, index+2, 1, dp);
        int hold = solve(prices, index+1, canBuy, dp);
        profit = max(sell, hold);
    }
    return dp[index][canBuy] = profit;
}

int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}


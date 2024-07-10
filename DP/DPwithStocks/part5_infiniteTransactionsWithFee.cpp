// same qn as part 2, can do as many transactions, just the added thing is here we have to pay
// transaction fee for a set of buy/sell. So just paying fee, reducing from profit when selling.

#include <iostream>
using namespace std;
#include <vector>

int solve(vector<int> &prices, int index, int canBuy, vector<vector<int>> &dp, int fee){
        
    if(index == prices.size()){
        return 0;
    }

    if(dp[index][canBuy]!=-1){
        return dp[index][canBuy];
    }

    int profit = 0;

    // buy
    if(canBuy == 1){
        int buy = - prices[index] + solve(prices, index+1, 0, dp, fee);
        int hold = solve(prices, index+1, canBuy, dp, fee);
        profit = max(buy, hold);
    }
    else{
    //sell
        int sell = prices[index] + solve(prices, index+1, 1, dp, fee) - fee;
        int hold = solve(prices, index+1, canBuy, dp, fee);
        profit = max(sell, hold);
    }
    return dp[index][canBuy] = profit;
}

int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp, fee);
}
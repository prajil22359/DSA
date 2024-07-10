#include <iostream>
using namespace std;
#include <vector>

// part 2 ko extension, tyaha number of transactions ma rok thiyena, yaha cha. yaha max 2 transactions
// garna pauda max profit nikal bhanyo. countTransaction pani euta variable thapyo. 3D dp. though can
// be done in 2D using odd even concept and merging countTransaction and canBuy to single variable ops.

int solve(vector<int> &prices, int index, int canBuy, vector<vector<vector<int>>> &dp, int countTransactions){
        
    if(index == prices.size()){
        return 0;
    }

    if(countTransactions == 2){
        return 0;
    }

    if(dp[index][canBuy][countTransactions]!=-1){
        return dp[index][canBuy][countTransactions];
    }

    int profit = 0;

    // buy
    if(canBuy == 1){
        int buy = - prices[index] + solve(prices, index+1, 0, dp, countTransactions);
        int hold = solve(prices, index+1, canBuy, dp, countTransactions);
        profit = max(buy, hold);
    }

    //sell
    else{

        int sell = prices[index] + solve(prices, index+1, 1, dp, countTransactions + 1);
        int hold = solve(prices, index+1, canBuy, dp, countTransactions);
        profit = max(sell, hold);
    }
    return dp[index][canBuy][countTransactions] = profit;
}

int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(prices, 0, 1, dp, 0);
}
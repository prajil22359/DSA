#include <iostream>
using namespace std;
#include <vector>

// simple qn. buy sell garnu cha to maximize the profit. you can do as many transactions you can
// within the price array, the condition being you cant buy twice consecutively, if you buy then
// you can either hold or sell. simple canBuy bool banako thats initially set 0, and toggles as
// you buy sell. profit lai as a portfolio amount bujhnu. if bought that day's price is subtracted,
// and if sold added, the difference you achieve is you profit / loss. Need to maximize it. Simple
// subsequences banako jastai hareko din ma herna. buy sell ya hold ke garna sakincha, sabai path
// try garne. O(n) time. because canBuy is either 0/1, so O(1).

int solve(vector<int> &prices, int index, int canBuy, vector<vector<int>> &dp){
        
    if(index == prices.size()){
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
        int sell = prices[index] + solve(prices, index+1, 1, dp);
        int hold = solve(prices, index+1, canBuy, dp);
        profit = max(sell, hold);
    }
    return dp[index][canBuy] = profit;
}

int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
    return solve(prices, 0, 1, dp);
}

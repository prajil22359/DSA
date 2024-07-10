// same qn ho buy sell 3 jastai. yesma bas limit k set gareko huncha. 2 ko thau ma k lekh accept huncha.
// Another thing to note is if you think a little cleverly canBuy ra countTransaction lai euta variable bata
// garna sakincha, with a variable operation.
// operation 0 se start hoga, and buy ya sell karne par increment hoga. ese k transactions allowed par 2k ops 
// honge, and if even no. of ops you can buy only, odd he to you can sell only. thus 2D dp.

// yo qn ma yo ops wala strategy use garera dekhako.
#include <iostream>
using namespace std;
#include <vector>

 int solve(vector<int> &prices, int index, int ops, int limit, vector<vector<int>> &dp){
        
        if(index == prices.size()){
            return 0;
        }

        if(ops == 2*limit){
            return 0;
        }

        if(dp[index][ops]!=-1){
            return dp[index][ops];
        }

        int profit = 0;

        // buy
        if((ops & 1)== false){  // even means canBuy.
            int buy = - prices[index] + solve(prices, index+1, ops+1, limit, dp);
            int hold = solve(prices, index+1, ops, limit, dp);
            profit = max(buy, hold);
        }
        else{
        //sell

            int sell = prices[index] + solve(prices, index+1, ops + 1, limit, dp);
            int hold = solve(prices, index+1, ops, limit, dp);
            profit = max(sell, hold);
        }
        return dp[index][ops] = profit;
    }

    int maxProfit( int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2*k+1));
        return solve(prices, 0, 0, k, dp);
    }
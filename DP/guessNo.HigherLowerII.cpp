// everytime hamro guess wrong hudai jada ni kunai time search space ma euta number
// matra huncha and we will eventually get it. tyo worst case ma kati paisa chahine 
// tyo return garne ho. loop chalaune for first guess and find the max amount when
// choosing wrong everytime. Aba mero according loop bata sabse max ans return garne
// taki for any first guess worst case amount needed nikalna sakios, tara ans is min 
// value from the loop.

#include <vector>
#include <iostream>
using namespace std;



    int solve(int start, int end, vector<vector<int>> &dp){
        
        if(start >= end){
            return 0;
        }

        if(dp[start][end]!=-1){
            return dp[start][end];
        }

        int maxi = 1e9;
        
        for(int i = start; i<= end; i++){
            maxi = min(maxi, i + max(solve(start, i-1, dp), solve(i+1, end, dp)));
        } 
        return dp[start][end] = maxi;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(1, n, dp);
    }
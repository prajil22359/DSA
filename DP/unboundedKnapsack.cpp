#include <iostream>
using namespace std;
#include <vector>

// 0/1 knapsack jastai nai ho, the thing is you can take multiple count of the same item.

int solve( int N, int W, int val[], int wt[], int index, vector<vector<int>> &dp){

    if(W <= 0){
        return 0;
    }

    if(index >= N){
        return 0;
    }

    if(dp[index][W] != -1){
        return dp[index][W];
    }

    // take 
    int take = 0;
    if((W - wt[index]) >= 0){
        // unbounded so can take the same item for multiple count.
        // present the opportunity to take the same item again, if doesnot want he can noTake it.
        take = val[index] + solve(N, W - wt[index], val, wt, index, dp);
    }

    // notTake
    int notTake = 0 + solve(N, W - 0, val, wt, index+1, dp);

    return dp[index][W] = max(take, notTake);
}

int knapSack(int N, int W, int val[], int wt[])
{   
    vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
    return solve(N, W, val, wt, 0, dp);
}
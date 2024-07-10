#include<iostream>
using namespace std;
#include<vector>

// same qn as longest increasing subsequence : tyasma length max garnu thyo, yesma sum max...


int solve(int arr[], int n, int curr, int pre, vector<vector<int>> &dp){
    
    // base cases
    if(curr == n){
        return 0;
    }

    if(dp[curr][pre + 1]!=-1){
        return dp[curr][pre + 1];
    }

    // jsut for scope.
    int take = 0;
    
    // take part
    // condition for take: strictly increasing
    if(arr[curr] > arr[pre] || pre == -1){
        take = arr[curr] + solve(arr, n, curr+1, curr, dp);
    }

    // not take part
    int notTake = 0 + solve(arr, n, curr+1, pre, dp);

    return dp[curr][pre + 1] = max(take, notTake);
}



int maxSumIS(int arr[], int n)  
{  
    // starting ma pre -1, kehi ni hunna to compare for strictly increasing condition so

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(arr, n, 0, -1, dp);
    
    // o(nlogn) more optimized but works only for calc length.
}  
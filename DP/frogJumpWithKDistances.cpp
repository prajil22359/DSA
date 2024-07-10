#include <iostream>
using namespace std;
#include <vector>

// there are n stones, qn says to find min cost to reach Nth stone,
// which if we keep in indices term is n-1th stair
// geek jump jastai ho ke, just the thing is tyaha 0/1 steps matra lina milthyo 
// bhane yaha k distances chan.

int solve(vector<int>& height, int j, int k, vector<int> &dp){

    // base case
    if (j==0) {
        return 0;
    }
    else if (j<0){
        return 1e9;
    }
    if(dp[j]!=-1){
        return dp[j];
    }

    int ans = 1e9;
    for (int i = 1; i <= k; i++)
    {
        ans = min(ans, solve(height, j-i, k, dp) + abs(height[j-i]- height[j]));
    }
    dp[j]= ans;
    return ans;

}

int minimizeCost(vector<int>& height, int n, int k) {
    // Code here
    vector<int> dp(n+1,-1);
    return solve(height, n-1 , k, dp);
}
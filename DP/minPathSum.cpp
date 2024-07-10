#include<iostream>
using namespace std;
#include<vector>

// path minimize garne thyo matrai. right or left route. 


int solve(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>> &dp){
    if(i == m-1 && j == n-1){ // dubai i, j pugyo bhane matrai trigger
        return grid[m-1][n-1];
    }

    if(i >= m || j >= n){
        return 1e9;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // right route
    int right = grid[i][j] + solve(grid, m, n, i+1, j, dp);

    // down route
    int down = grid[i][j] + solve(grid, m, n, i, j+1, dp);

    return dp[i][j] = min(right, down);
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    return solve(grid, m, n, 0, 0, dp);
}
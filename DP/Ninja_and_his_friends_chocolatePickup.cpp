#include<iostream>
using namespace std;
#include<vector>

// 2 players will be trying to move to the base of the grid -> each with its own coordinates
// (i1, j1) and (i2, j2), but the thing to notice is that i1 == i2 always, as they are both
// starting from i = 0, and will be moving one step down the grid always. So just i will suffice
// Thus 3 states to keep track of i, j1, j2.

// Also now there are 9 possible moves combinly for the both players. player1 can move down, with
// which player2 can be moving in any of the 3 directions. So 3x3 making 9 possible moves.
// we will be doing it with a for loop, and also keeping in check that if j1 == j2, the choclate
// there will be counted only once. 

int fn(vector<vector<int>>& grid, int n, int m, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
    
    // invalid path. // need to keep this condition before lower base case.
    if(j1 >= m || j2 >= m || j1 < 0 || j2 < 0){
        return -1e9;
    }

    // base case
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j2];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        } 
    }
    
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int maxi = -1e9;
    for(int k1 = -1; k1 <= 1; k1++){
        for(int k2 = -1; k2 <= 1; k2++){
            int ans = -1e9;
            if(j1 == j2){
                ans = grid[i][j2] + fn(grid, n, m, i+1, j1 + k1, j2 + k2, dp);
            }
            else{
                ans = grid[i][j1] + grid[i][j2] + fn(grid, n, m, i+1, j1 + k1, j2 + k2, dp);
            }
            maxi = max(ans, maxi);
        }
    }
    return dp[i][j1][j2] = maxi; 
    
}


int solve(int n, int m, vector<vector<int>>& grid) {
    
    // 3D dp.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // n x m grid
    return fn(grid, n, m, 0, 0, m-1, dp);
}
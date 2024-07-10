// unique paths given obstacles in grid. simple ho right ya down jane case ma first ensure
// no obstacle there.
#include<iostream>
using namespace std;
#include<vector>
int solve(int m, int n, int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){

    if(i == m-1 && j == n-1){
        return 1;
    }

    if(i >= m || j >= n){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int right = 0;
    int down = 0;

    // yo case halna important, we cant even be checking going out of bound. 
    if(i < m-1){
        if(obstacleGrid[i+1][j] == 0){
            right = solve(m, n, i+1, j, obstacleGrid, dp);
        }
    }
    if(j < n-1){
        if(obstacleGrid[i][j+1] == 0){
            down = solve(m, n, i, j+1, obstacleGrid, dp);
        }
    }
    return dp[i][j] = right + down;
    // return right + down;
}


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    // important : if the starting index (0,0) ma nai obstacle cha bhane return 0. No way.
    // similarly is the case if obstacle in (m-1, n-1) but when we are taking any step we ensure no
    // obstacle so that case is handled already.

    if(obstacleGrid[0][0] == 1){
        return 0;
    }

    vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
    return solve(m, n, 0, 0, obstacleGrid, dp);
}
#include<iostream>
using namespace std;
#include<vector>

// LEETCODE 120

// triangle[i][j] --> ith row jth column. triangle.size() --> n, means n ota rows chan. 
// i can get to n-1. j is as much as i is. eg: i=4, 5th row ma 5 elements hunchan. so j = 5 too.  

int solve(vector<vector<int>>& triangle, int n, int i, int j, vector<vector<int>> &dp){

    // one base case is enough. when reached last row. 
    if(i == n-1){
        return triangle[i][j];
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    // next row same index
    int down = triangle[i][j] + solve(triangle, n, i+1, j, dp);


    // next row index + 1
    int diagonal = triangle[i][j] + solve(triangle, n, i+1, j+1, dp);

    return dp[i][j] = min(down, diagonal);
}


int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp( n+1, vector<int> (n+1, -1));
    return solve(triangle, n, 0, 0, dp);
}
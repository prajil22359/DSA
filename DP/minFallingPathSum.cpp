#include <iostream>
using namespace std;
#include <vector>

// memoization could not pass, so tabulation. tabulation ma alik bujhera garnu parcha hai,
// copy paste haina sadhai.

int solveMem(vector<vector<int>> &matrix, int n, int i, int j, vector<vector<int>> &dp){

        if(i == n-1){
            return matrix[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = 1e9, diagonallyLeft = 1e9, diagonallyRight = 1e9;

        // Move directly down
        if (i < n - 1) {
            down = matrix[i][j] + solveMem(matrix, n, i + 1, j, dp);
        }

        // Move diagonally down to the left
        if (j - 1 >= 0) {
            diagonallyLeft = matrix[i][j] + solveMem(matrix, n, i + 1, j - 1, dp);
        }

        // Move diagonally down to the right
        if (j + 1 < n) {
            diagonallyRight = matrix[i][j] + solveMem(matrix, n, i + 1, j + 1, dp);
        }

        return dp[i][j] = min(down, min(diagonallyLeft, diagonallyRight));

    }

int solveTab(vector<vector<int>> &matrix, int n){

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // analyse base case
    // last row filled
    for(int j = 0; j < n; j++){
        dp[n-1][j] = matrix[n-1][j];
    }

    // last row bata mathi ko row banaudai jane ho.
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j <= n-1; j++){

            int down = 1e9, diagonallyLeft = 1e9, diagonallyRight = 1e9;
        // default values, for when if cond doenot allow, large number indicating invalid path.

            // Move directly down
            if (i + 1 < n) {
                down = matrix[i][j] + dp[i + 1][j];
            }

            // Move diagonally down to the left
            if (j - 1 >= 0) {
                diagonallyLeft = matrix[i][j] +  dp[i + 1][j - 1];
            }

            // Move diagonally down to the right
            if (j + 1 < n) {
                diagonallyRight = matrix[i][j] +  dp[i + 1][j + 1];
            }
    
            dp[i][j] = min(down, min(diagonallyLeft, diagonallyRight));
        }
    }

    int mini = 1e9;
    for(int j = 0; j < n; j++){
        mini = min(dp[0][j], mini);
    }
    return mini;
    
} 



int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // int mini = 1e9;
    // for(int j=0; j<n; j++){
    //     int ans = solveMem(matrix, n, 0, j, dp);
    //     mini = min(ans, mini);
    // }
    // return mini;

    return solveTab(matrix, n);
}
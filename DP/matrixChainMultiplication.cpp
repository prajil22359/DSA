// A mxn multiplied with B nxp --> needs m*n*p multipications.
// Given we need to multiply n number of matrices, we have to group in 2's for actually calc multiplication.
// So we are talking about how to put the brackets cause ans toh same aega but multiplications needed
// will be different and can thus be minimized. 

// Its partitioning dp. ADA lectures ma cha..

#include<iostream>
using namespace std;
#include<vector>

// bracket lagaudai jane ho -> sab jaga lagaera try garne. base case huncha jaba single matrix aucha.
// harek dui matrix lai multiply garda multiplication ops lagchan, tyaslai minimize garne.

// solve(i,j) bhaneko min multiops required to multiply matrices from Ai to Aj.
// dimension of Ai is arr[i-1] x arr[i]. 

 int solve(int n, int arr[], int i, int j, vector<vector<int>> &dp){
        // base case
        if(i==j){
            // single matrix need not multiply
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    
        int minimizedOps = 1e9;

        // trying everywhere in which i can put brackets.
        for (int k = i; k < j; k++)
        {
            int ans = solve(n, arr, i , k, dp) + solve(n, arr, k+1, j, dp) + arr[i-1]* arr[k]* arr[j];
            // Ai dekhi Ak multiply garda m, n ke huncha, tyasaigari Ak+1 dekhi Aj ke huncha. 
            // Ra yesari yo duita lai multiply garna multip ops (m*n*p) ke hun 
            // arr[i-1], a[k]  and a[k], a[j]. yeslai multiply garda a[i-1] * a[k] * a[j] 
            // yeti multiplication ops. lagnu parne ho.
            minimizedOps = min(minimizedOps, ans);
        }
        return dp[i][j] = minimizedOps;
    
    }
    
    int matrixMultiplication(int N, int arr[])
    {   
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return solve(N, arr, 1, N-1, dp);
    }
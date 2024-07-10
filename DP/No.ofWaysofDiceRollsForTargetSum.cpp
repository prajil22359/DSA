#include<iostream>
using namespace std;
#include<vector>

// ways to climb stairs qn jastai ho. finding distinct ways to make a target sum x using n dices with 
// faces 1 to m. So, solve(m,n,x) tyahi ways khojcha.
// aaba euta kura bhan, x sum banauna n dices bata isn't it equal to the sum over ways through which 
// x-i sum be made using n-1 dices, i being the face used. kina bhane tyaspachi ta 1 dice ith face use
// garera sum banaunu parcha, no choice there. just like nth stair pugna ways to reach n-1th + ways to
// reach n-2th gareko thim. 


long long solve(int m, int n, int x, vector<vector<long long>> &dp){

    // base case
    if(n == 0 && x == 0){
        return 1;
    }

    if(n < 0 || x < 0){
        return 0;
    }

    if(dp[n][x]!=-1){
        return dp[n][x];
    }

    long long  totalWays = 0;
    for (int i = 1; i <= m; i++)
    {
        totalWays += solve(m, n-1, x-i, dp);
    }
    return dp[n][x] = totalWays;
}


long long noOfWays(int M , int N , int X) {
    // n ra x change bhairaha cha
    vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
    return solve(M,N,X, dp);
}
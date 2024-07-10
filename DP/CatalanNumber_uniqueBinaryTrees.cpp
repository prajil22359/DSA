#include<iostream>
using namespace std;
#include<vector>

// Given an integer n, return the number of structurally unique BST's (binary search trees)
// which has exactly n nodes of unique values from 1 to n. CATALAN number 2nCn / (n+1)

int solve(int n, vector<int> &dp){

    if(n == 0 || n == 1)
        return 1;

    if(dp[n]!=-1)
        return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
       // ith element lai root banauda, 1 -> i-1 left subtree ma hunchan bhane i+1 to n right subtree ma
       // what matters is kitne elements he subtree mein, not konse he. 
       ans += 1 * solve(i-1, dp) * solve(n-i, dp);
       // multiply kina gareko, basics of counting -> And theory. root i, rakhe pachi no other way.
       // right subtree ma solve(n-i) ways, left subtree ma solve(i-1) ways..

    }
    return dp[n] = ans;
}

int numTrees(int n) {
    // dp
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

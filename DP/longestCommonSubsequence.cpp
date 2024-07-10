// 2 strings are given, need to find the longest subsequence common in both
// common element check garnu paryo, we will use recursion to check the other elements
// memoization could not clear the last test case, so used tabluation here

#include <iostream>
using namespace std;
#include <vector>

int solve(string text1, string text2, int i, int j, vector<vector<int>> &dp){
    
    // base case when index tries to go out of bounds
    if(i==text1.size() || j==text2.size()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    // yadi common element cha bhane euta count badhcha and give recursion to solve for rest
    if(text1[i]==text2[j]){
        return dp[i][j] = 1 + solve(text1, text2, i+1, j+1, dp);
    }
    else{
        return dp[i][j] = max(solve(text1,text2, i+1, j, dp), solve(text1, text2, i, j+1, dp));
    }
}

// memoization ma 0 dekhi n samma gako ani backtrack gardai ans banayau.
// tabulation ma n dekhi 0 jane

int solveTab(string text1, string text2){

    // step 1: make dp
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));

    // step 2: analyze base case
    // for (int k = 0; k <= text2.size(); k++)
    // {
    //     dp[text1.size()][k]=0;
    // }

    // for (int k = 0; k <= text1.size(); k++)
    // {
    //     dp[k][text2.size()]=0;
    // }

    // step 3: base case bata final ans tira lagne. n -> 0 . 

    for (int i = text1.size()-1; i <= 0; i++)
    {
        for (int j = text2.size()-1; j <= 0; j++)
        {
                // yadi common element cha bhane euta count badhcha and give recursion to solve for rest
            if(text1[i]==text2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
    }

    return dp[0][0];

}

int longestCommonSubsequence(string text1, string text2) {
    // int i = 0;
    // int j = 0;
    // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
    // return solve(text1, text2, i, j, dp);

    return solveTab(text1, text2);
}

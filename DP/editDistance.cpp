#include<iostream>
using namespace std;
#include<vector>
#include <string>

// ops needed to convert word1 to word2

int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp){

    // base case
    // if elements saki halyo bhane ke garne?
    // yadi word1 sake, word2 ko baaki elements insert garnu parcha.
    // n-1th index element - jth element +1, yati elemnets insert. 
    if(i==word1.size()){
        return word2.size() - j;
    }

    // similarly yadi word2 sake, delete garnu parcha word1 ka remaining elements.
    if(j==word2.size()){
        return word1.size() - i;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(word1[i]==word2[j]){
        return 0 + solve(word1, word2, i+1, j+1, dp);
    }
    else{
        // will need to do any of the three operations : insert, delete or replace

        // insert : jth element word1 ma insert gareko jasto garne, thus now we   
        // look for equality in j+1th element and ith. i ta use bhakai chaina while 
        // inserting so, one operation used so 1 + f(i, j+1).

        // delete : just delete the ith element, i pachi ko elements sanga equality 
        // khojnu. 1 + f(i+1, j).

        // replace : replace garera same banauda bhaigo, one operation used now keep    
        // checking for the rest array 1 + f(i+1, j+1)

        return dp[i][j] = 1 + min(min(solve(word1, word2, i, j+1, dp), solve(word1, 
        word2, i+1, j, dp)), solve(word1, word2, i+1, j+1,dp));
    }
}

int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, -1));
    return solve(word1, word2, 0, 0, dp);
}
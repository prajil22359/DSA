#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

    // sabse lamo subsequence that should be palindrome. brute force ma, sab subsequence banaune palindrome 
    // ho ki nai check garne ani return garne max length wala lai.
    // euta simple observation is need. intuitive nabhae yaad gar: hamro ans is the longest common subsequence 
    // between the given string and its reverse.
    // a1 a2 a3 i0 a4 i1 i2 a5 i3 a6 -> string    longest palindromic subsequence i0 i1 i2 i3
    // a6 i3 a5 i2 i1 a4 i0 a3 a2 a1 -> its reverse
    // aba her yesma lcs nikalda, kam bhaihalcha, we get the ans as palindrome agadi pachadi euta ho.
    // i3 == i0, i2 == i1, and viceversa.

int longestCommonSubsequence(string text1, string text2, int i, int j, vector<vector<int>> &dp){

    if(i == text1.size() || j == text2.size()){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(text1[i]==text2[j]){
        return dp[i][j] = 1 + longestCommonSubsequence(text1, text2, i+1, j+1, dp);
    }
    else{
        return dp[i][j] = max(longestCommonSubsequence(text1, text2, i+1, j, dp),
                   longestCommonSubsequence(text1, text2, i, j+1, dp));
    }
}

// memory limit exceeded aucha, tabulation laijau. space ni optimize garna sakincha. i ra i+1 rakhi matrai
int solveTab(string text1, string text2){
 
    vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));

    for(int i = text1.size()-1; i>=0; i--){
        for(int j = text2.size()-1; j>=0; j--){
            
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

int solveSpaceOptimized(string text1, string text2){
    // vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));
    vector<int> currRow(text2.size()+1, 0);
    vector<int> nextRow(text2.size()+1, 0);

    for(int i = text1.size()-1; i>=0; i--){
        for(int j = text2.size()-1; j>=0; j--){
            
            if(text1[i]==text2[j]){
                currRow[j] = 1 + nextRow[j+1];
            }
            else{
                currRow[j] = max(nextRow[j], currRow[j+1]);
            }
        }
        nextRow = currRow;
    }
    // last ma i = 0 ko lagi solve huncha, thats the nextRow.
    return nextRow[0];
}




int longestPalindromeSubseq(string s) {

    string reversedString = s;
    reverse(reversedString.begin(), reversedString.end());
    vector<vector<int>> dp(s.size()+1, vector<int> (reversedString.size()+1, -1));
    // return longestCommonSubsequence(s, reversedString, 0, 0, dp);
    return solveSpaceOptimized(s, reversedString);
}

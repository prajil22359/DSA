#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm> 


// DP METHOD
// Thorai optimize garna lai hola prunign gareko cha, nagarda ni chalthyo simple if else ra recursion le.

bool checkValidString(string s) {
    int n = s.size();
    // dp[index][openBracket] represents if the substring starting from index i is valid with j opening brackets
    vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
    // base case: an empty string with 0 opening brackets is valid
    dp[n][0] = true;

    for (int index = n - 1; index >= 0; index--) {
        for (int openBracket = 0; openBracket <= n; openBracket++) {
            bool isValid = false;

            // '*' can represent '(' or ')' or '' (empty)
            if (s[index] == '*') {
                isValid |= dp[index + 1][openBracket + 1]; // try '*' as '('

                // opening brackets to use '*' as ')'
                if (openBracket > 0) {
                    isValid |= dp[index + 1][openBracket - 1]; // try '*' as ')'
                }
                isValid |= dp[index + 1][openBracket]; // ignore '*'
            } else {
                // If the character is not '*', it can be '(' or ')'
                if (s[index] == '(') {
                    isValid |= dp[index + 1][openBracket + 1]; // try '('
                } else if (openBracket > 0) {
                    isValid |= dp[index + 1][openBracket - 1]; // try ')'
                }
            }
            dp[index][openBracket] = isValid;
        }
    }

    return dp[0][0]; // True if the entire string is valid with no excess opening brackets
}


// GREEDY METHOD
// dherai sajilo just think, agadai bata herda hami closing parenthesis lai track garne, 
// if we get one closing bracket going from ahead and at that time there is no opening bracket or the
// wildcard to cancel it off, the ans should be false.


class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int lol=0,star=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==')' && lol==0 && star==0)
            return false;
            else if(s[i]==')' and lol>0 and star==0)
            lol--;
            else if(s[i]==')' and lol==0 and star>0)
            star--;
            else if(s[i]==')' and lol>0 and star>0)
            lol--;
            else if(s[i]=='(')
            lol++;
            else if(s[i]=='*')
            star++;
        }
        int lol1=0,star1=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(' && lol1==0 && star1==0)
            return false;
            else if(s[i]=='(' and lol1>0 and star1==0)
            lol1--;
            else if(s[i]=='(' and lol1==0 and star1>0)
            star1--;
            else if(s[i]=='(' and lol1>0 and star1>0)
            lol1--;
            else if(s[i]==')')
            lol1++;
            else if(s[i]=='*')
            star1++;
        }
       
        return true;
    }
};
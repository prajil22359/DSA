#include<bits\stdc++.h>
using namespace std;

// solveMemo and solveTab doesnot pass this problem.
// solveOptimized is best

bool customComparator(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0]; // Sort by the first item in ascending order
    }
    return a[1] > b[1]; 
    // Sort by the second item in descending order if the first items 
    // are equal
}

int solveMemo(vector<vector<int>> &envelopes, int index, int pre,   
            vector<vector<int>> &dp){
    // LIS lagaune ho yaha matrai

    // base case
    if(index == envelopes.size()){
        return 0;
    }

    if(dp[index][pre + 1] != -1){
        return dp[index][pre+1];
    }

    // take
    int take = 0;
    if(pre == -1 || (envelopes[index][1] > envelopes[pre][1])){
        take = 1 + solveMemo(envelopes, index+1, index, dp);
    }
    // not take
    int notTake = 0 + solveMemo(envelopes, index+1, pre, dp);

    return dp[index][pre + 1] = max(take, notTake);
}

int solveTab(vector<vector<int>> &envelopes){
    int n = envelopes.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    // no need to explicitly analyze base case, as all are initialized to zero already.

    // recursion --> index 0 to n-1 and pre from -1 to n-1
    // here in tabulation from n-1 to 0

    for (int curr = n-1; curr >= 0; curr--)
    {
        // for (int pre = curr-1; pre >= 0; pre--), more optimized,when start from curr - 1
        for(int pre = curr-1; pre >= -1; pre--)
        {          
            // take
            int take = 0;
            if(pre == -1 || envelopes[curr][1] > envelopes[pre][1]){
                take = 1 + dp[curr+1][curr+1];
            }
            // not take
            int notTake = 0 + dp[curr+1][pre+1]; 
            // 2nd value pre ke liye he dp mein, starting form -1 so we need to offset it always.

            dp[curr][pre + 1]=max(take, notTake);
        }
    }
    
    return dp[0][-1 + 1];
}

int solveOptimized(vector<vector<int>> &envelopes){

    if(envelopes.size() == 0){
        return 0;
    }

    vector<int> ans;
    ans.push_back(envelopes[0][1]);

    for(int i = 1 ; i < envelopes.size(); i++){
        if(envelopes[i][1] > ans.back()){
            ans.push_back(envelopes[i][1]);
        }
        else{
            // binary search for lower bound
            int lowerBound = lower_bound(ans.begin(), ans.end(), 
            envelopes[i][1]) - ans.begin();
            ans[lowerBound] = envelopes[i][1];
        }
    }
    return ans.size();
}


int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), customComparator);
    // int n = envelopes.size();
    // vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    // return solveMemo(envelopes, 0, -1);
    return solveOptimized(envelopes);
    return solveTab(envelopes);

}


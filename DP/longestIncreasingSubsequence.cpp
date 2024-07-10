#include<iostream>
using namespace std;
#include<vector>

// take not take gari subsequence banaune ho recursion use gari, just the thing is strictly 
// increasing cond. hunu paryo for take. pre is the index to track that. simple recursion lagaune then. 


int LISC(int n, int i, vector<int>& a, int pre, vector<vector<int>> &dp){
    
    // base case
    if(i==n){
        return 0;
    }

    if(dp[i][pre+1]!=-1){
        return dp[i][pre+1];
    }

    int take = 0;
    // take
    // take has condition so checking for strictly increasing case.
    // pre is the index which was last selected for the subsequence, pre is enough 
    // as it will correspond to the largest number from the existing subsequence to compare with
    if(pre == -1 || a[i] > a[pre] ){
        take = 1 + LISC(n, i+1, a, i, dp);
    }
    
    // not take  
    int notTake = 0 + LISC(n, i+1, a, pre, dp);   

    return dp[i][pre+1] = max(take, notTake);
}

// O(nlogn) TC and O(N) SC code 
int solveOptimized(vector<int> &a){

    if(a.size() == 0){
        return 0;
    }

    vector<int> ans;
    ans.push_back(a[0]);
    // pahilo element ko sanga compare garaunu ra. 
    // i ni tyasaile 1 bata start garne

    for(int i = 1 ; i < a.size(); i++){
        if(a[i] > ans.back()){
            ans.push_back(a[i]);
        }
        else{
            // binary search for lower bound
            int lowerBound = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[lowerBound] = a[i];
        }
    }
    return ans.size();
}


int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    // dp ma
    // i -> 0 to n-1
    // pre -> -1 to n-1
    // so have that 1 as offset. a[pre] yaha offset chahidaina. yaha pre==-1 ko lagi case banaideko cha. 

    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    
    // pre = -1 for initial case. just someone to compare with.
    return LISC(n, 0, nums, -1, dp);
}
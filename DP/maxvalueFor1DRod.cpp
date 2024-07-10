#include<iostream>
using namespace std;
#include<vector>

// min coins jastai ho

int solve(vector <int> &price, int length, vector<int> &dp){

	// base case
	if (length == 0){
		return 0;
	}
	if(length <0){
		return -1e9;
	}

	if(dp[length]!=-1){
		return dp[length];
	}

	int maxValue = 0;
	for( int i = 1; i <= price.size(); i++){
		int ans = price[i-1] + solve(price, length - i, dp);
		maxValue = max(maxValue, ans);
	}
	return dp[length] = maxValue;
}

int cutRod(vector<int> &price, int n)
{
	vector<int> dp(n+1, -1);
	return solve(price, n, dp);

}

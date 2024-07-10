#include<iostream>
using namespace std;
#include<vector>

int solve(vector<int> &values, vector<int> &weights, int index, int capacity, vector<vector<int>>&dp){

	// base case
	if(index==weights.size()){ 
		// cant add value when no item // out of bound cond.
		return 0;
	}

	if(dp[index][capacity]!=-1){
		return dp[index][capacity];
	}

	int take = 0;
	// take
	if (capacity >= weights[index]) {
		take = values[index] + solve(values, weights, index + 1, capacity - weights[index], dp);
	}

	// not take
	int notTake = 0 + solve(values, weights, index+1, capacity -0, dp);

	return dp[index][capacity]=max(take, notTake);

}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{	

	vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
	// Write your code here
	return solve(values, weights, 0, w, dp);
}
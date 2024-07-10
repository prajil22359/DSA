#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// like time coefficient = time taken uptil and inclusind a dish * satisfaction level of the dish
// maximize like time coefficient, you can choose to discard any dish and take dishes in any order


class Solution {
public:

    int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){

        // base case
        if(index == satisfaction.size()){
            return 0;
        }

        if(dp[index][time]!=-1){
            return dp[index][time];
        }

        int include = (time + 1)*satisfaction[index] + solve(satisfaction, index + 1, time + 1, dp);
        int exclude = 0 + solve(satisfaction, index + 1, time, dp);
        return dp[index][time] = max(include, exclude);

    }

    int maxSatisfaction(vector<int>& satisfaction) {

        // sorting is necessary because if you are taking a negative dish, take it as early as possible,
        // and also to serve dishes with higher satisfaction value as late as possible to maximize.

        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(satisfaction, 0, 0, dp);
    }
};
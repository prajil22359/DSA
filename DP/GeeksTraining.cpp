#include <iostream>
using namespace std;
#include <vector>

// 2d array deko cha. points for every day for every move is given there. need to maximize 
// points in the days given. constraint that they cant do the same task on two consecutive days.
// state is any day with what was the last activity.

// initially -1 as the lastActivity. So need to offset the dp's 2nd element by 1. 

// memoization couldnot pass, way to big constraints, so used tabulation.

int solve(vector<vector<int>>& points, int n, int lastActivity, int day, vector<vector<int>> &dp){

    // base case
    if(day == n){
        return 0;
    }

    if(dp[day][lastActivity + 1] != -1){
        return dp[day][lastActivity + 1];
    }
    
    int maxi = -1e9;
    for(int i = 0; i<=2; i++){
        int ans = 0;
        if(i != lastActivity || lastActivity == -1){
            ans = points[day][i] + solve(points, n, i, day+1, dp);
        }
        maxi = max(ans, maxi);
    }
    return dp[day][lastActivity + 1] = maxi;

}


int solveTab(vector<vector<int>> &points, int n){
    
    vector<vector<int>> dp(n+1, vector<int>(4, 0));
    
    // 2 loops for 2D dp,  index n-1 to 0, lastActivity 2 to -1.
    for (int day=n-1; day>=0; day--){
        for(int lastActivity = 2; lastActivity >= -1; lastActivity--){
            
            // copy paste as it is just change function call to dp
            int maxi = -1e9;
            for(int i = 0; i <= 2; i++){
                int ans = 0;
                if(i != lastActivity || lastActivity == -1){
                    ans = points[day][i] + dp[day + 1][i + 1]; // i+1 for offseting 
                }
                maxi = max(ans, maxi);
            }
            dp[day][lastActivity + 1] = maxi;
               
        }
    }
    return dp[0][-1 + 1];

}


int maximumPoints(vector<vector<int>>& points, int n) {
    
    vector<vector<int>> dp(n+1, vector<int>(4, -1));
    // return solve(points, n, -1, 0, dp);
    return solveTab(points, n);
}
#include <iostream>
using namespace std;
#include <vector>

// euta height ko array deko cha, stairs haru ko height hun 0 to n-1th stair. 
// minimum energy nikalnu cha for climbing to the n-1th stair from 0th.
// energy taken is absolute difference between heights.

// min cost to climb stairs jastai feel cha

int solve(vector<int>& height, int k, vector<int> &dp){

    if(k==0) {
        return 0;
    }
    // its not a valid way at all to go from 0 to n-1th stair.
    // I am trying to solve from n-1 to 0, so the destination must be 0.
    // this way if its not a valid way, send positive infinity, cause we looking for minimum here.

    if(k<0) {
        return 1e9; 
        // INT_32_MAX doesnot work, because I will be adding it to something 
        //and that will due to integer overflow turn the number negative so use a smaller number 1e9.
    }

    // memoization reading
    if(dp[k]!=-1){
        return dp[k];
    }

    int finalStep1 = solve(height, k-1, dp) + abs(height[k]-height[k-1]);
    int finalStep2 = solve(height, k-2, dp) + abs(height[k]-height[k-2]);
    return dp[k] = min (finalStep1, finalStep2);
}



int minimumEnergy(vector<int>& height, int n) {
    // Code here

    vector<int> dp(n+1, -1);

    // ANS : min cost to reach n-2th stair + cost from n-2 to n-1 , min cost to reach n-3th stair + cost from n-3 to n-1
    return solve(height, n-1 , dp);
}

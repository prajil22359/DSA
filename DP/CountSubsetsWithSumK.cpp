// distinct ways, subset take not take logic

#include <iostream>
using namespace std;
#include <vector>

    long long int solve(int arr[], int n, int sum, int index, vector<vector<long long int>> &dp){
        
        
        // sabai elements check garna jaroori cha. normally yadi sum == 0 huda, agadi kunai element line
        // kura audaina thyo, take side le sadhai 0 ways nai return garthyo. There is only one way to make
        // sum 0, by notTaking any. tara yaha haina, yaha element 0 ni huna sakcha, so check only when sab
        // option dekhliya, at out of bound situation.
        
        // euta sikh ki ans ma mod lagauna bhaneko cha bhane sub problem ma ni lagaunu, else its way too big..
        
        
        if(index == n & sum == 0){
            return 1;
        }
        
        if(index > n){
            return 0;
        }

        if(sum < 0){
            return 0;
        }
        
        if(dp[index][sum]!= -1){
            return dp[index][sum];
        }
    
        //take
        long long int take = (solve(arr, n, sum - arr[index], index+1, dp)) % 1000000007 ;
    
        long long int notTake = solve(arr, n, sum, index+1, dp) % 1000000007;
        //notTake
        
        return dp[index][sum] = take + notTake;

    }
    
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        
        // 2D dp , sum and index changing.
        vector<vector<long long int >> dp(n+1, vector<long long int > (sum+1, -1));
        int ans = solve(arr, n, sum, 0, dp) % 1000000007;
        return ans;

    }
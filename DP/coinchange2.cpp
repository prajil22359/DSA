// distinct ways to make the amount : coin change. u have unlimited supply of each coin.

#include <iostream>
using namespace std;
#include <vector>

// int solve(int amount, vector<int> &coins){

//     if(amount == 0){
//         return 1;
//     }

//     if(amount < 0){
//         return 0;
//     }

//     int ways = 0;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         ways += solve(amount - coins[i], coins); 
//     }
// }

// YO TARIKA LE PERMUTATIONS DIYO. 2111 ra 1211 lai different lincha. jasle ans dinna.

int solve( int amount, vector<int> &coins, int index, vector<vector <int>> &dp){

    // euta denomination ko jati linu cha lihal ani matrai arko denominations ma jane.

    // infinite supply ko case ma, you can take the same denomination again, so index nabadha in take
    // case, presenting the opportunity to take again.
    // yesari herna milyo, take ma duita case -> amount ta ghatcha dubaima, tara euta ma index++,
    // arko ma index as it is. tara point is duita case banai faida chaina, index nabadhaune, 
    // yadi tyaslai linu chaina bhane notTake garihalcha next time.


    // base case
    if(amount == 0){
        return 1;
    }

    if(amount < 0){
        return 0;
    }

    if(index >= coins.size()){
        return 0;
    }

    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }


    int take = solve(amount - coins[index], coins, index, dp);  // no index + 1 here.
 
    int notTake = solve(amount, coins, index+1, dp);

    return dp[index][amount] = take + notTake;

}

int change(int amount, vector<int>& coins) {

    // 2D dp
    vector<vector <int>> dp(coins.size()+1, vector<int>(amount + 1, -1));
    return solve(amount, coins, 0, dp);
}
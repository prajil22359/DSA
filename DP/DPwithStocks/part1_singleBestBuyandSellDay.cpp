#include <iostream>
using namespace std;
#include <vector>

int maxProfit(vector<int>& prices) {

    // Brute force bho 2 loop
    // int ans = 0;
    // for(int i = 0; i < prices.size(); i++){
    //     for(int j = i+1; j < prices.size(); j++){
    //         ans =  max(ans, prices[j]- prices[i]);
    //     }
    // }
    // return ans;

    // better way to do it in 1 pass
    // approach where we select selling day, and track minPriceToBuy. eutai loop ma bhaihalcha.
    int minPriceToBuy = prices[0];
    int profit = 0;
    for(int i = 1; i < prices.size(); i++){ 
        // day to sell -> 1 to n-1.
        // cant sell in day 0, also thats the min price to buy byfar for i = 1.
        int difference = prices[i] - minPriceToBuy; 
        // you would certainly sell at minPriceToBuy, sab previous day sanga check garna jaroori chaina, 
        // max lai track gar bas.
        profit = max(profit, difference);
        minPriceToBuy = min(minPriceToBuy, prices[i]);
    }
    return profit;
}

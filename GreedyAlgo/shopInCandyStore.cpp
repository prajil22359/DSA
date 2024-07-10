#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

vector<int> candyStore(int candies[], int N, int K)
{
    // sorting makes it easy to decide what to pay for and what to take as free
    sort(candies, candies + N);
    
    // min price nikaldai
    // you buy the min priced one and take for free the max priced one
    int buy = 0;
    int free = N-1;
    int minAmount  = 0;
    while(buy <= free){
        minAmount += candies[buy];
        buy ++ ;
        free = free - K;
    }
    
    // max price nikaldai, using the offer fully
    // you buy the max priced one and take for free the min priced one
    buy = N-1;
    free = 0;
    int maxAmount  = 0;
    while(free <= buy){
        maxAmount += candies[buy];
        buy -- ;
        free = free + K;
    }
    
    return {minAmount, maxAmount};
}
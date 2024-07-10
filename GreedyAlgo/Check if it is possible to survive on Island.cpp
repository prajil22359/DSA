#include <iostream>
using namespace std;

int minimumDays(int S, int N, int M){
    
    // how much unit do we need food in total to survive : S * M
    
    // so how many days, we will need to buy food, if we can buy N units in a day.
    // --> ceil of (S * M) / N
    
    int totalFood = S * M;
    int daysNeededToBuy = 0;
    
    if(totalFood % N  == 0){
        daysNeededToBuy = totalFood / N;
    }
    else{
        daysNeededToBuy = totalFood / N + 1;
    }
    
    int numSundays = S / 7; // you can't buy on sundays.
    int totalBuyingDays = S - numSundays;
    
    if(daysNeededToBuy > totalBuyingDays){
        return -1;
    }
    
    return daysNeededToBuy;
    
}
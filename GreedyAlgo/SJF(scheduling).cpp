#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 


class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        
        sort(bt.begin(), bt.end());
        // keep a clock
        long long clock = 0;
        long long waitingTimeSum = 0;
        
        for(auto i: bt){
            waitingTimeSum += clock;
            clock += i;
        }
        return waitingTimeSum/bt.size();
        
    }
};

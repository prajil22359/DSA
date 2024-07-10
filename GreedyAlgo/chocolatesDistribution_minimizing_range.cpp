#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

// easy qn: choosing packets such that the range is minimized, that is the diff between
// maximum chocolates one gets and minimum one gets ko difference is minimized.

// N>M constraint cha, else: not possible wala case ni hunthyo. print -1, just handle it as said.

long long findMinDiff(vector<long long> a, long long n, long long m){
//code
    sort(a.begin(), a.end());
    
    // checking all possible m sized window of this sorted array.
    // why only a contiguous subarray, because we want to minimize the range.
    // sorted cha yaar, najik ko elements kai bich ma kam diff niskincha ni.
    long long start = 0;
    long long end = m-1;
    long long miniDiff = 1e9;
    while(end <= a.size()-1){
        miniDiff = min(miniDiff, a[end] - a[start]);
        start++;
        end++;
    }
    return miniDiff;
}   
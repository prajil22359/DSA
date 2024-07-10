// just an extension to merge intervals qn, just added the new element we needed to add in this intervals
// vector, and run it into the merge fn from the previous qn.class Solution {

// optimized is finding the small range where overlapping will happen and carry merge intervals there only,
// not in whole array.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    //find the interval that will be overlapping

    // left segment
    int i = 0;
    int n = intervals.size();
    vector<vector<int>> result;
    while( i < n && intervals[i][1] < newInterval[0]){
        result.push_back(intervals[i]);
        i++;
    }

    // overlapping segment
    while( i < n && intervals[i][0] <= newInterval[1]){
        newInterval[0] = min(intervals[i][0], newInterval[0]);
        newInterval[1] = max(intervals[i][1], newInterval[1]);
        i++;
    }
    result.push_back(newInterval);

    // copy right segment
    while(i < n){
        result.push_back(intervals[i]);
        i++;
    }
    return result;
}

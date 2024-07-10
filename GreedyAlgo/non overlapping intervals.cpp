#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 


class Solution {
public:

    // crux: find the minimum number of intervals to erase to make intervals non overlapping.
    // yadi gahiro sochne ho bhane, it is the maximum non overlapping intervals.-> N meetings in a room qn.

    static bool cmp(vector<int> &intervals1, vector<int> &intervals2){
        return intervals1[1] < intervals2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);

        vector<int> last;
        last = intervals[0];
        int count = 1;
        int n = intervals.size();

        // yo qn ma equals is considered non overlapping
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= last[1]){
                count++;
                last = intervals[i];
            }
        }
        return n - count;
        
    }
};
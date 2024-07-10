 // greedy ko qn ho, sabai range lai check garna not worthy, sort garera rakhne ani check garne if previous 
// interval sanga overlapping cha yo naya interval bhanera.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){

            // merge condition
            if( intervals[i][0] <= ans.back()[1] ){
                // okay so its certainly overlapping, naya interval last interval ko bhitrai aucha.
                // aba kura ho, purai bhitrai parcha ki nai. what should be the closing of this interval
                // -> maximum of the two ends.
                    vector<int> temp = {ans.back()[0], max(intervals[i][1], ans.back()[1])};
                    ans.pop_back();
                    ans.push_back(temp);
            }
            else{
                ans.push_back(intervals[i]);
            }
    }
        return ans;
    }
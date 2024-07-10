#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// find the maximum number of meetings that can be performed in a meeting room.
// sort in ascending according to the end time. And count all the possible meetings.
// meeting 2 is possible if the start time of it is greater than the end time of 
// meeting already scheduled.

bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
    
int maxMeetings(int start[], int end[], int n)
{
    vector<pair<int, int>> meetings;
    
    for(int i = 0; i < n; i++){
        meetings.push_back(make_pair(start[i], end[i]));
    }
    
    sort(meetings.begin(), meetings.end(), cmp);
    
    int count = 1;
    int last_end = meetings[0].second;
    
    for(int i = 1; i < n; i++){
        if(meetings[i].first > last_end){
            count++;
            last_end = meetings[i].second;
        }    
    }
    
    return count;
}
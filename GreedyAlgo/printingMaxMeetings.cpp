#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
    
// same qn ho maximizing number of meetings possible in one meeting room, just tyaslai print
// garaunu parne thyo, the only thing to do was sort garera order haracha, so store the initial
// order as a 3rd item to the vector. and that would just help identify ki yo ans actually kun 
// meeting ma thyo initial ordering anusar


// custom comparator rakhda last ko 3ta test case pass bhaena so, finishing time lai first item 
// banaera default sort gareko.

// static bool cmp(vector<int> a, vector<int> b){
//     return a[1] < b[1];
// }

vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){

    vector<vector<int>> meetings;
    
    for(int i = 0; i < N; i++){
        meetings.push_back({F[i], S[i], i+1});
    }
    
    sort(meetings.begin(), meetings.end());
    
    vector<int> ans;
    ans.push_back(meetings[0][2]);
    int last_end = meetings[0][0];
    
    for(int i = 1; i < N; i++){
        if(meetings[i][1] > last_end){
            ans.push_back(meetings[i][2]);
            last_end = meetings[i][0];
        }    
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}
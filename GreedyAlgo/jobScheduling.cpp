// Follow the given steps to solve the problem:

// Sort all jobs in decreasing order of profit. 
// Iterate on jobs in decreasing order of profit.For each job , do the following : 
// Find a time slot i, such that slot is empty and i < deadline and i is greatest.Put the job in 
// this slot and mark this slot filled. 
// If no such i exists, then ignore the job. 


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp(Job a, Job b){
        return a.profit > b.profit; // a ko profit greater than b ko, bhane agadi -> descending
}
    
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr, arr + n, cmp);
    
    int maxDeadline = 0;
    for(int i = 0; i < n; i++){
        maxDeadline = max(maxDeadline , arr[i].dead);
    }
    
    vector<int> schedule(maxDeadline + 1, -1); // 1 to maxDeadline day // 1based indexing
    
    int numJobs = 0;
    int maxProfit = 0;
    for (int i = 0; i < n; i++){
        
        int currProfit = arr[i].profit;
        int currDeadline = arr[i].dead;
        int currId = arr[i].id;
        // kunai ni job last deadline ko din garne kosis huncha, taaki agadi ka din aru kunai kam garna
        // sakios
        
        for (int k = currDeadline; k >= 1; k--){
            if(schedule [k] == -1){
                // cout << currProfit << endl;
                schedule [k] = currId;
                maxProfit += currProfit;
                numJobs ++;
                break;
            }
        }
    }
    
    return {numJobs, maxProfit};
} 
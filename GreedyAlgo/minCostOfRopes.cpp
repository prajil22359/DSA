#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>  
#include <queue>  
    
// need to merge all the n ropes into 1 rope. the cost of merging two ropes is the sum of their length.
// need to minimize the cost. The greedy algo says keep merging the two smallest ropes,
// every step ma min cost to merge 2 ropes lidai merge garne --> kind of what we do in Huffman coding. 

// aba her every time, least 2 sized ropes chahiyo, you wont be sorting everytime. --> min heap use garne


//Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n) {
    
    // making the min heap
    priority_queue< long long, vector<long long>, greater<long long>> minHeap;
    
    for(int i = 0; i < n; i++){
        minHeap.push(arr[i]);
    }
    
    long long cost = 0;
    // will add the cost while merging the two smallest rope, thats equivalent to the merged rope size;
    
    
    // continue merging as long as single element is left.
    while ( minHeap.size() > 1){
                
        long long smallest;
        smallest = minHeap.top();
        minHeap.pop();
        
        long long secondSmallest;
        secondSmallest = minHeap.top();
        minHeap.pop();
        
        long long merged = smallest + secondSmallest;
        cost += merged;
        minHeap.push(merged);
    }
    return cost;
}
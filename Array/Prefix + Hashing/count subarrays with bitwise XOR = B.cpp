#include<iostream>
using namespace std;
#include<vector>
#include <unordered_map>

int solve(vector<int> &A, int B) {
    int n1 = A.size(); 
    int x = 0; 
    int count = 0;
    unordered_map<int, int> map1; // map ma 1st value x value, ra second count of prefix that get that value.
    for(int i = 0; i < n1; i++){
        x = x ^ A[i];
        
        if(x == B){
            count ++;
        }
        
        int target = x ^ B;
        
        
        if(map1.find(target) != map1.end()){
            count += map1[target];
        }
        
        if(map1.find(x) == map1.end()){
            map1[x] = 1;
        }
        else{
            map1[x]++;
        }
    }
    
    return count;

}

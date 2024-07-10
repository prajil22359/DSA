// an element is a leader if all the element to its right is smaller that the element.
// so last element of the array is definitely a leader.
// the logic is simple : if any element is greater than the last leader, its a leader
// herihalnu equal ma ke garne bhanera, leader manne ki nai, qn anusar.

#include <iostream>
using namespace std;
#include <vector>

vector<int> leaders(int n, int arr[]) {
    vector<int> ans;
    ans.push_back(arr[n-1]);

    for(int i = n-2; i >= 0; i--){
        if(arr[i] > ans.back()){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
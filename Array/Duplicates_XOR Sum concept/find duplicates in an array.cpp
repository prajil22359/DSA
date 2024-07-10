#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

// set membership test garihal,
// print all those duplicate elements

int findDuplicate(vector<int> &arr) 
{
    unordered_set <int> set1;
    for(auto i : arr){
        if(set1.count(i)){
            cout << i; 
        }
        else{
            set1.insert(i);
        }
    }
}
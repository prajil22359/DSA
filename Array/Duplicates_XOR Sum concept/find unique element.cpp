#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// Problem Stmt:
// one of the elements of the array occurs only once while the others occur twice, find that element.

// below is the brute force, sabai ko occurence nikalyo, ra check garyo jasko 1 cha return that. O(nlogn)

// Optimized khatra bit manipulation le garna sakincha.
// using XOR property, a^a = 0, a^0 = a. so for loop lagaera XOR garda, double
// wala sabai cancel out, what we get is the ans.

// Sum formula use : sab dui choti chan ni euta chodi, 2 * total sum le minus garide, bhetihalcha
// hamro single element.

// similarly we can find the unique element when the unique element occurs twice but all others once.

int findUnique(int *arr, int size)
{

    // XOR concept
    // int ans = 0;
    // for(int i = 0; i < size; i++){
    //     ans = ans ^ arr[i];
    // }
    // return ans;



    // brute force
    unordered_map<int, int> dict;

    for(int i = 0; i < size; i++){
        if(dict.count(arr[i])){
            dict[arr[i]]++;
        }
        else{
            dict[arr[i]] = 1;
        }
    }

    for(auto i : dict){
        if(i.second == 1){
            return i.first;
        }
    }
}
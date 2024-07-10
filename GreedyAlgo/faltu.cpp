#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int countOccurrences(vector < int > arr, int x) {
    int n = arr.size();
    int it = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    int it1 = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    return it1 - it + 1;
}
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// simple lower bound of x, le x bhako pahilo index di halcha, upper bound le jut thulo dihalcha.
// yiniharu yeskai lagi ta baneka hainan but yes, yaha kam lage.

int countOccurrences(vector < int > arr, int x) {
    int n = arr.size();
    int it = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int it1 = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
    return it1 - it;
}

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// longest AP qn kai part ho, yesma euta specific difference ko lagi matra longest AP nikalnu
// cha. i loop as it is cha. j wala loop chalena because we need not keep track for every possible 
// difference. i bhanda agadi kun element hunu parne thanaicha, a[i] - d. just check if tyo already kunai 
// AP form gardaicha bhane add its length. 


int longestSubsequence(vector<int>& A, int d) {
    int n = A.size();
    unordered_map<int, int> dp; 
    // unordered map for element which carry the AP with diff d, single element ko lagi 1.

    int ans = 0; 
    for (int i = 0; i < n; i++)
    {
        int temp = A[i] - d;
        int tempAns = 0;

        if(dp.count(temp))      // yadi tyo element exist garcha bhane her if tyo yo diff liyera AP form   
                                // gardaicha bhane. yadi exist garcha bhane 1 value ta huncha nai.
            tempAns = dp[temp];

        dp[A[i]] = tempAns + 1 ; // +1 for including ith element
        ans = max (ans, dp[A[i]]); 
    }

    return ans; 
}
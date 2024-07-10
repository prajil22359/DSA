#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:

// ith element utha, tyasko pachadi jati ni elements chan, sab euta potential AP form garna sakchan. 
// hami euta map banauchau ith element ko lagi, sabai  i-1 elements corresponding euta difference value
// bhetcha, tyo difference lai key banaera value ma 1 + dp[j,d] lekhchau. It means yahi difference
// bhako jth element pachadi pani etti elements chan, adding them. pachhdai bhaneko array ko left bujhnu.

// i am inspecting all previous value of i : let that be j. one possible AP is this i and jth element.
// now if j also had d as a difference when inspecting its previous values, then that count can be added.
// as it will also join to the AP of i and j. 

// [3, 6, 9, 12] —>[ [:], [3:1], [6:1,  3:2], [9:1, 6: 1, 3:3] —> max lai track gar 3 aucha. ans will be 4, cause this map includes element with d differnce before i, tyo i pani count ma include garnu paryo ni..

    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();

        unordered_map<int, int> dp[n+1]; // map kina bhane difference negative ni huna sakcha,
                                        // offset use garera 2d array bata ni bhaehalcha

        // unordered map ma yadi noexisting element ko count sodhda 0 dincha. tyo kam lagcha.

        // dp[i] -> ith element corresponding map. dp[i][d] -> ith element corresponding difference d ko
        // count. -> count ke ta, ith element pachadi kati element chan d difference ka.

        int ans = 1; // initialized to 1, as that is the minimum nouber of times you would see a
                    // difference. 2 length ko array huda ans 2 hunu parcha, tyasko lagi ni kam    
                    // lagcha.

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {   
                int d = A[i] - A[j];
                dp[i][d] = 1 + dp[j][d];  // neighbour ko dictionary ma ni check gardai
                ans = max (ans, dp[i][d]); // max value chahiyo count ko.
            }
        }
        return ans + 1; // ans le ta maximium count matrai khojeko cha, tyo element i pani include garnu 
                        // paryo ni AP ma.
    }
};
#include <iostream>
using namespace std;
#include <vector>

// min swaps find gar to make two subsequences strictly increasing. Her kunai ni index ma ya ta swap
// garchas, ya gardinas
// no swap if its already increasing. nums1[i] > nums1[i-1] and nums2[i] > nums2[i-1]
// swap if swapping makes it increasing.  nums1[i] > nums2[i-1] and nums2[i] > nums1[i-1].
// her esto ni condition aucha jasma noswap and swap duabi eligible hunchan. so its possible.

// first element ko lagi -1, add garcham dubai array ma. So they are always eligible for noswap.
// tara swap ko lagi pani eligible hunchan, so yo na soch ki -1 halera noswap option matra chodyo haina.
// pahilo element swap garera pani subsequence increasing banauna sakincha.
// for eg: 1,4,5,7 and 3,2,4,9 . 1st index swap gari bhaigo.

// aba her euta bool swapped variable rakhnu parcha, so that actual swap garnu na paros.
// yadi swapped cha bhane arko array bata compare garnu parcha. so your code should manage that.

int solve(vector<int> &nums1, vector<int> &nums2, bool swapped, int index, 
    vector<vector<int>> &dp){
    int ans = 1e9;

    // base case
    if(index == nums1.size()){
        return 0;
    }

    if(dp[index][swapped]!=-1){
        return dp[index][swapped];
    }

    int pre1 = nums1[index-1];
    int pre2 = nums2[index-1];

    if(swapped){
        swap(pre1, pre2);
    }

    // no swap
    if(nums1[index] > pre1 && nums2[index] > pre2){
        ans = 0 + solve(nums1, nums2, 0, index+1, dp);
    }

    //swap
    if(nums1[index] > pre2 && nums2[index] > pre1){
        ans = min(ans, 1 + solve(nums1, nums2, 1, index+1, dp));
    }

    return dp[index][swapped] = ans;
}

int minSwap(vector<int>& nums1, vector<int>& nums2) {
    
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
 
    int swapped = 0; // initially
    int index = 1;   // index initially 1, because -1 dummy haleko cha agadi

    // 2D dp lagcha because index and swapped is changing.
    // Yesma tabulation ra space optimization very possible and worth it try once.

    vector<vector<int>> dp(nums1.size()+1, vector<int>(2, -1));

    return solve(nums1, nums2, swapped, index, dp);
}
// qn le ke bhancha bhane: euta array deko chu, subarrays banauna sakincha, ti madhye tyo subarray de,
// jas ko elements ko product nikalda maximum niskos. negative elements pani chan hai.

// subarray ? contiguous chunk of the array, non empty. yadi sabai subarray nikalnu cha bhane kasari 
// nikalne ? --> 
// for (int i = 0; i<n; i++){
//     for(int j = i; j<n; j++){
//          v.push_back(arr[j])
//     }
//     print v; // all the subarrays.
// }

// brute force way -> sabai subarray nikal ani check garihal..


// case wise thinking logic : see the problem is with odd number of negative integers, only then I 
// have to think else take all elements for product.
// in the odd negatives case : the thing is we just need to eliminate one of the negaatives, and take all.
// but doing so will  partition the array into two: suffix and prefix our ans will be maximum product
// from those two when done removing one negative each time. 

// aba her, euta tarika ke ho bhane right se :  multiply karte ja saare elements ko ek ek karke,
// track the maximum product achieved.
// similarly do it from left side. our ans is max among those two maxes.
// why this should work?
// her etti ta bujhiyo ki kunai euta negative element lai hataune ho -> prefix suffix banchan, 
// tyo prefix suffix elements ko product madhye max line.
// tyasobhae sabai index ko lagi prefix suffix herihal. tyahi gareko ho yesma. 

// aa 0 bhae ke garne ta, zero bhae qn paritioned into 2 subarrays already cause no one is taking 0.
// reset gardine prefix, suffix lai.

#include<iostream>
using namespace std;
#include<vector>


// process 1 : prefix suffix wala
int solve(vector<int> &nums){

    int prefix = 1;
    int suffix = 1;
    int ans = -1e9; 
    for (int i = 0; i < nums.size(); i++)
    {   
        // rest when found 0
		if(prefix == 0) prefix = 1;
		if(suffix == 0) suffix = 1;

		prefix *= nums[i]; 
		suffix *= nums[nums.size()-1-i]; 

        ans = max(ans, max(prefix, suffix));
    }
    return ans;
}
// euta doubt thiyo if no positive ra zero cha bhane 0 ans dina sakcha ki nai bhanera. dincha kina bhane
// zero ko case after being considered for ans handle gareko cha. ki product zero aae, aba dekhi ko lagi
// prefix suffix reset.


// process 2 : considering ki max negative can also be the max product given a negative number comes
int solve2(vector<int> &nums){
    int maxPositive = 1;
    int maxNegative = 1;

    int prod = 1;
    for (int i = 0; i < nums.size()-1; i++)
    {
        prod= prod * nums[i];

        maxPositive = max(maxPositive, prod);
        maxNegative = min(maxNegative, prod);

        if(prod == 0){
            prod = 1;
        }
    }

    return maxPositive;  
}




int maxProduct(vector<int>& nums) {
    // return solve(nums);
    return solve2(nums);
}

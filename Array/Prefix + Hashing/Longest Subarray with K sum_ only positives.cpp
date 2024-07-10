#include <iostream>
using namespace std;
#include <vector>

// 2 pointer approach for non negative array.
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        int sum = 0;
        int left = 0;
        int right = 0;
        int maxi = 0;
        while(right < N){
            sum += A[right];

            while(left <= right && sum > k){
                sum -= A[left];
                left ++;
            }

            if(sum == k){
                maxi = max (maxi, right - left + 1);
            }
            right ++;
        }
        return maxi;
    }
};

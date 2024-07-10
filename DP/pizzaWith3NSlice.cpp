// 3N slice ko pizza cha. kura etti ho ki, talai kunai euta slice utha bhancha, tyasko anticlockwise 
// direction ko first remaining slice ra clockwise direction ko first remaining slice arka dui sathi le
// khaidinchan/. that means out of all k slice, you will be eating k/3 slice. Our work is to maximize 
// the size of slices we eat. 

// aba bhan ke yo house robber in circular street jasto lagiraha chaina. adjacent lai na li, 
// maximize garne. kura tyahi ho, tyaha jastai yaha ni soln is max of two cases of linear street problem:
// linear street from 0 to n-2 --> including first slice and linear street from 1 to n-1 --> with last slice

#include <iostream>
using namespace std;
#include <vector>

int solve(vector<int> &slices, int start, int end, int sliceToEat, 
        vector<vector<int>> &dp){
        if(sliceToEat == 0){
            return 0;
        }
        if(start>end){
            return 0;
        }

        if(dp[start][sliceToEat]!=-1){
            return dp[start][sliceToEat];
        }

        int take = slices[start] + solve(slices, start + 2, end, sliceToEat 
                    - 1, dp );
        int notTake = 0 + solve(slices, start + 1, end, sliceToEat - 0, dp);
        return dp[start][sliceToEat] = max(take, notTake);
    }


    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();

        // 2D dp, because start and sliceToEat is both changing
        vector<vector<int>> dp1 (k+1, vector<int> (k+1, -1));
        // sliceToEat = k/3 , still dp ma k nai liyera garidim, ese hi..

        int case1 = solve(slices, 0, k-2, k/3, dp1);

        vector<vector<int>> dp2 (k+1, vector<int> (k+1, -1));
        int case2 = solve(slices, 1, k-1, k/3, dp2);

        return max(case1, case2);
    }
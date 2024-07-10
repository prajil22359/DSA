#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        // {twice occuring, missing}
        // Use Maths formulas, single variable khojda sum till n lai use garthyau.
        // but yaha duita variable cha, so sum of n sqred pani chahincha
        
        
        // SABLAI LONG MA LAGNU HAI, INT MA BHIYAUDAINA, SABAI LAI NI, maile n lai nagarera gaaro bhayo ekchin
        
        long N = n;
        
        long sum = 0;
        long sqrSum = 0;
        for(long i : arr){
            sum += i;
        }
        
        for(long i : arr){
            sqrSum += (i*i);
        }
        
        // first n natural's sum
        long nSum = N*(N+1)/2;
        
        // first n sqred sum
        long nSqrSum =  N * (N+1) * (2*N + 1) / 6;

        // eqns
        long x = sum - nSum;
        long y = sqrSum - nSqrSum;

        
        long B = (x + y/x)/2;
        long A = B - x;
        
        vector<int> ans;
        ans.push_back((int)B);
        ans.push_back((int)A);
        
        return ans;
        
    
    }
};


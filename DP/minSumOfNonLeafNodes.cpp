// qn ma binary trees haru bana, ani kehi calculating formula deka chan to calc non-leaf nodes.
// Hamile minimum sum of non leaf nodes return garnu parne ho. 
// [1,..., n] leaf nodes inorder ma diyeko cha. aba yo array lai partition garnu parcha. 
// [1, i] leaf nodes left subtree ma, bhane [i+1, n] right subtree ma. aba according to qn,
// root node ko value is product of maximum value of leaf node in left and right subtree.
// duita leaf nodes samma rahda non leaf node bancha, euta bachda bandaina, base case hit.
// sab partition check garne tiniharuko intervals merge garne.  

#include <iostream>
using namespace std;
#include <vector>
#include<map> // unordered map use gariena because it doesnot have inbuilt hash function for pair

int solve(vector<int> &arr,map <pair<int,int> , int> &maximum, int start, int end, vector<vector<int>>&dp) 
{
    if(start == end){ // euta matrai element cha, so its leaf, adding 0 to non leaf ko sum
        return 0;
    }

    if(dp[start][end]!=-1)  
        return dp[start][end];

    int mini = 1e9;
    for(int i = start; i < end; i++){  // i != end -> as that would lead no leaf node in right subtree. 
        int ans = maximum[{start, i}] * maximum[{i+1, end}] + solve(arr, maximum, start, i, dp) + solve
            (arr, maximum, i+1, end, dp);
        mini = min(mini, ans);
    }

    return dp[start][end] = mini;
}



int mctFromLeafValues(vector<int>& arr) {

    // sabai range ko maximum value compute gareko // pre processing
    map <pair<int,int> , int> maximum;
    for(int i = 0; i < arr.size(); i++){
        maximum[{i,i}] = arr[i];
        for(int j = i+1; j < arr.size(); j++){
            maximum[{i,j}] = max(arr[j], maximum[{i, j-1}]); 
        }
    }

    vector<vector<int>> dp(arr.size()+1, vector<int> (arr.size()+1, -1));
    return solve(arr, maximum, 0, arr.size()-1, dp);
}
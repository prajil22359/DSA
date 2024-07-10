#include<bits/stdc++.h>
using namespace std;

// ke bhaneko cha bhane height maximize gar.
// so hamile euta cuboid ko dimension lai sort garchau, such that the largest dimension of any cuboid 
// is the height-> last column height ko.
// aba, sabai cuboids haru lai first column anusar -> width ko basis ma sort garne.

bool checkIfStackable(vector<int> newBox, vector<int> base){
    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2]){
        return true;
    } 
    else{
        return false;
    }
}

int solveMemo(int n, int i, vector<vector<int>> &cuboids, int pre, vector<vector<int>> &dp){
    
    // base case
    if(i<0){
        return 0;
    }

    if(dp[i][pre+1]!=-1){
        return dp[i][pre+1];
    }

    int take = 0;
    // take
    if(pre == -1 || checkIfStackable(cuboids[i], cuboids[pre]) ){
        take = cuboids[i][2] + solveMemo(n, i-1, cuboids, i, dp); // i set as pre now bcz its taken.
    }
    // cuboids[i][2] indicates height, thats what we are trying to maximize in this qn.
    
    // not take  
    int notTake = 0 + solveMemo(n, i-1, cuboids, pre, dp);   

    return dp[i][pre+1] = max(take, notTake);
}


int maxHeight(vector<vector<int>>& cuboids) {

    // step 1
    for(auto &i : cuboids){
        sort(i.begin(), i.end());
        // last column now is height.
    }

    // step 2
    sort(cuboids.begin(), cuboids.end());

    
    //LIS logic

    int n = cuboids.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    return solveMemo(n, n-1, cuboids, -1, dp);
}

// increasing subsequence ma smallest element ta linai parcha tyasai gari
// stacking up cuboids ma one with the highest base ta linai parcha. so thats n-1th cuboid,
// as we have sorted already.
// so we are taking n-1th, for the eligibility fn we make, for it pre = -1. 
// tyaspachi next i= n-2 jancha, yesko lagi ni take not take dubai hunchan. 
// tara take ko lagi condition huncha, it should comply to the checkIfStackable fn,
// where it checks if ith cuboid -> newBox can be placed on top of pre th cuboid -> the base
// the base case is thus when i<0 out of bound, where we return 0.
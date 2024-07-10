
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	struct Node *left, *right;
};

// root to any node ko path, ko sum k bhae add in ans.
// simple recursively traverse gar till leaf nodes. 
// path to leaf nodes ko sum = k wala qn ma leaf node pugepachi sum == k bhae count garinthyo,
// bhane yaha harek new node in the path from root ma check garim



class Solution
{
    public:
    
    void solve(Node* root, int sum, int sumTillNow, vector<int> &path, vector<vector<int>> &ans){
        
        // out of bound gae nothing to do.
        if(root == NULL){
            return;
        }
        
        // yo node line.
        path.push_back(root -> key);
        sumTillNow += root -> key;
        // ani check garne ki if now path sum == k
        if(sumTillNow == sum){
            ans.push_back(path); // bhae ans ma line
        }
        
        solve(root -> left, sum, sumTillNow, path, ans);
        solve(root -> right, sum, sumTillNow, path, ans);
        
        // backtracking ma garnu parcha. parent ko lagi path vector as it is chodeko.
        path.pop_back();
        
    }
    
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        
        int sumTillNow = 0;
        vector<int> path;
        vector<vector<int>> ans;
        solve(root, sum, sumTillNow, path, ans);
        return ans;   
    }
};
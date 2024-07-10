#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:

    // diameter is the max node count between ay two nodes in a binary tree.
    // two nodes select garnu ani find garnu is not the way.
    // the logic that helps solve this :
    
    // dont think I will be explaining well this rightnow,
    // tara kura ke ho bhane if we maximize the value 1 + leftheight + rightheight,
    // for everynode, we will get the longest path b/w any two nodes. 
    
    // aba brute force ta tyahi huncha ki, recursively reach every node and find this value, 
    // update the maximum if its larger. O(n^2). A way to get down time complexity is using a 
    // map and precompute the height values, that way we can in O(n)

    // however there is an efficient approach: height for a node nikalda ni leftheight ra 
    // right height chahincha, ta tyati khera nai tyo node ko lagi longest path nikal, ani 
    // track this maximum over the solution.


    int solve(TreeNode* root, int &maxi){
        if(root == NULL){
            return 0;
        }

        int lh = solve(root -> left, maxi);
        int rh = solve(root -> right, maxi);

        int ans = 1 + lh + rh;
        maxi = max(maxi, ans);

        return 1 + max(lh, rh);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        solve(root, maxi);
        // return maxi - 1; // max le node count garcha, longest path, ma tara yaha edge nikal 
        // bhaneko cha. So -1;
    }
};
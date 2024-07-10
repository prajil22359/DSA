#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:


// height balanced if the difference of left subtree's and right subtree's height is atmost 1

    // naively huncha if sabai nodes ko lagi height precompute gare, tara the better way
    // would be to include the balanceCheck within the height fn.
    // recursively height nikalchas ni nikaldai jaa, yadi katai kunai node ma height imbalance
    // cha bhane -1 return garidinu.

    int solve(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int lh = solve(root -> left);
        int rh = solve(root -> right);

        // yadi kati esto unbalance bhako paiyoo bhane turuntai return gardine -1;
        if(lh == -1 || rh == -1){
            return -1;
        }

        if(abs(lh - rh) > 1){
            return -1;
        }

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        if(solve(root) == -1){
            return false;
        }
        return true;;
        
    }
};
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

    // height of binary tree ? --> 1 + max(leftSubtree height, rightSubtree height).

    int maxDepth(TreeNode* root) {

        // base case
        if(root == NULL)    return 0;
    
        int leftSubTreeHeight = maxDepth(root -> left);
        int rightSubTreeHeight = maxDepth(root -> right);

        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }
};
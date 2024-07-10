#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:

    // threaded links like we did in morris traversal, tyahi concept use garnu parcha.
    // just do whats said, connect in preorder in right links, keeping left links null.
    // if anything in left bring in right. make the NL and LR connections finding the 
    // predecessor element.
 
    TreeNode* findPredecessor(TreeNode* root){
        // left subtree ko rightmost element.
        TreeNode* pred = root -> left;
        while(pred -> right != NULL){
            pred = pred-> right;
        }
        return pred;
    }

    void flatten(TreeNode* root) {
        
        while(root != NULL){
            if(root -> left){
                TreeNode* pred = findPredecessor(root);
                pred -> right = root -> right; // LR connected
                root -> right = root -> left;  // NL connected
                root -> left = NULL;
            }
            else{
                root = root -> right;
            }
        }
    }
};
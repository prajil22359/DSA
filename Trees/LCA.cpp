#include <iostream>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
    int val;  
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
// Lowest common ancestor nikalnu cha, duitai nodes ko path nikal, given nodes ko najik ko
// common node nai hamro answer ho. This is brute force. 
// A little observation gives the efficient approach- > LCA is the root whose left and right
// subtree has one each of these two required nodes.
// logic tyahi node pata garne, ho code tala cha alik intuitively catch garna sakeko ta chuina,
// but yahi ho, recursively tyo node lai mathi falne ho. 
//


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //base case
        if (root == NULL) {
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);


        // this is the crux of this qn, the node which could find the 2 nodes in either of its 
        // subtree is the lowest common ancestor; 
        if(left != NULL && right != NULL){
            return root; 
        }
        else if(left != NULL){
            return left; // returning the not null one. 
        }
        else if(right != NULL){ // this is when right == null
            return right; // again, returning the not null one.
        }
        else{
            return NULL;
        }
    }
};
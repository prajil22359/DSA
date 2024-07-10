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

    // node count garne tarika tyahi recursive sabai visit gardai count garnu nai ho.
    // but we can use the complete property. there will be subrees that are full. so there
    // nodeCount will be 2^d - 1. To check if its full, the left boundary's height and right
    // one should be equal.


    int leftBoundary(TreeNode* root){

        if(root == NULL){
            return 0;
        }
        return 1 + leftBoundary(root -> left);
    }

    int rightBoundary(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + rightBoundary(root -> right);
    }


    int countNodes(TreeNode* root) {

        if(root == NULL){
            return 0;
        }

        int lb = leftBoundary(root);
        int rb = rightBoundary(root);

        if(lb == rb){

            return (1 << lb)  - 1;
        }

        int left = countNodes(root -> left);
        int right = countNodes(root -> right);
        return 1 + left + right;
    }
};
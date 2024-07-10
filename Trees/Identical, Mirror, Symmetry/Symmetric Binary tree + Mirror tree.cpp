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

    bool isMirror(TreeNode *r1, TreeNode *r2)
    {
        if(r1 == NULL && r2 == NULL)    return true;
        if(r1 != NULL && r2 == NULL )   return false;
        if(r1 == NULL && r2 != NULL )   return false;
        
        // when neither is null.

        // isIdentical bhanda alik tweaked, mirror ma, left portion of one tree should be 
        // equivalent to right portion of the other tree.

        bool part1 = isMirror(r1 -> left, r2 -> right);
        bool part2 = isMirror(r1 -> right, r2 -> left);
        if(r1 -> val == r2 -> val &&  part1 == true && part2 == true){
            return true;
        }
        // if not then, false.
        return false;
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root -> left, root -> right);
    }
};
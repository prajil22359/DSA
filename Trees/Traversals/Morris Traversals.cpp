#include <iostream>
#include <vector>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// threaded links ko concept ho, parent ma pugna saknu paryo, recursion huda sajilo aba nabhae, 
// hami links banauchau to get to the root. 

// inorder ma pahila left traverse garnu parcha, so root bata left janu aghi root ma farkine 
// link banaune, predecessor find garincha, left subtree ko rightmost node, inorder ya preorder 
// dubai ma last element traverse hune tyahi ho, so tyaha bata node ma farikna euta link banaincha.

// yadi left null ho bhane ta curr lai ans ma hali right tira lagne, but if left is not null
// find the predecessor -> leftsubtree ko rightmost node establish link from this to curr
// oonly then visit left



class Solution {
public:
    // Function to perform iterative Morris inorder traversal of a binary tree
    vector<int> getInorder(TreeNode* root) {

        // Vector to store the inorder traversal result
        vector<int> inorder;

        // Pointer to the current node, starting from the root
        TreeNode* cur = root;
        
        // Loop until the current node is not NULL
        while (cur != NULL) {

            // If the current node's left child is NULL
            if (cur->left == NULL) {
                // Add the value of the current node to the inorder vector
                inorder.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            } 
            
            else {
                // If the left child is not NULL, find the predecessor (rightmost node
                // in the left subtree)
                TreeNode* prev = cur->left;

                // predecessor khojna jada, prev -> right null hunu paryo, taba samma right
                // gairakhne, tara esto ni huna sakcha ni ki threaded link pahilai baisakeko thyo
                // and we are just looping around, tyasto hunu hudaina, so yadi prev -> right ==
                // curr ayo, that would mean link was already established so stop.

                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the predecessor's right child is NULL, establish a temporary link
                // and move to the left child
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } 
                
                else {
                    // If the predecessor's right child is already linked, remove the link,
                    // add current node to inorder vector, and move to the right child
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        // Return the inorder traversal result
        return inorder;
    }
};

// yasailai preorder garnu pare. while making the threaded link put curr in preorder vector, only 
// then move left and eventually right. NLR. just a change in place of line 78 to 70.
                            
                        
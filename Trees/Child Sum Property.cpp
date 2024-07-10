#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    
    
    int solve(Node* root){
        
        if(root == NULL){
            return 1;
        }
        
        // if its leaf node.
        if(root -> left == NULL && root -> right == NULL){
            return 1;
        }
        
        int checkForRoot = 0;
        int left = 0;
        int right = 0;
        
        if(root -> left) left = root -> left -> data;
        if(root -> right) right = root -> right -> data;

        
        if(root -> data == (left + right)){
            checkForRoot = 1;
        }
        
        return checkForRoot & solve(root -> left) & solve(root -> right);

    }
    
    
    
    
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        return solve(root);
    }
};
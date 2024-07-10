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

// naive solution: find the path and the kth element from node is our ans.
// this one is optimized. we find the node, and as we find, we start decrementing 
// k, such that as it gets to 0 we return it, we dont let the ans be overwritten, by
// updating k to a big number, which is practically locking ans.


Node* solve(Node* root, int &k, int node){
    
    if(root == NULL) return NULL;
    if(root -> data == node) return root;
    
    Node* leftAns = solve(root -> left, k, node);
    Node* rightAns = solve(root -> right, k, node);
    
    if(leftAns != NULL && rightAns == NULL){
        k --;
        if(k == 0){
            
            // ans lock
            k = 1e9;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL){
        k --;
        if(k <= 0 ){
            
            // ans lock
            k = 1e9;
            return root;
        }
        return rightAns;
    }
    return NULL;
}


// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root, k, node);
    if(ans == NULL || ans-> data == node) return -1;
    else return ans -> data;
}

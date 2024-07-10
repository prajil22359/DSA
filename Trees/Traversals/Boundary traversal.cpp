#include <iostream>
using namespace std;
#include <vector>

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
public:

    bool isLeaf(Node* node){
        if(node -> left == NULL && node -> right == NULL){
            return true;
        }
        else{
            return false;
        }
    }


    void leftBoundary(Node* root, vector<int> &ans){
    
        if(root == NULL || isLeaf(root) ){
            return;
        }
    
        // taking values as we go down.
        ans.push_back(root -> data);
    
        if(root -> left){
            leftBoundary(root -> left, ans);
        }
        else{
            leftBoundary(root -> right, ans);
        }
    
    }
    
    void rightBoundary(Node* root, vector<int> &ans){
    
        if(root == NULL || isLeaf(root)){
            return;
        }
    
        if(root -> right){
            rightBoundary(root -> right, ans);
        }
        else{
            rightBoundary(root -> left, ans);
        }
        
        // backtracking garda ans ma add gardai jancha. taki reverse order ma paios..
        ans.push_back(root -> data);
        
    }
    
    void findLeaf(Node* root, vector<int> &ans){
        // dfs gar ani check for leaf: in left to right order.
    
        if(root == NULL){
            return;
        }
        if(isLeaf(root)){
            ans.push_back(root -> data);
        }
    
        findLeaf(root -> left, ans);
        findLeaf(root -> right, ans);
    }
    
     vector<int> boundary(Node* root){
    
        vector<int> ans;
    
        if(root == NULL) return ans;
    
        if(isLeaf(root)){
            ans.push_back(root -> data);
            return ans;
        }
    
        ans.push_back(root -> data);
    
        // left boundary
        leftBoundary(root -> left, ans);
    
        // leaf
        findLeaf(root, ans);
    
        rightBoundary(root -> right, ans);
    
        return ans;
    
     }

};
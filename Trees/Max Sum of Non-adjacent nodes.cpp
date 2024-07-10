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
  
  
    // pair ko pahilo value is when we take the node and next is when we dont take.
  
    pair<int, int> solve(Node* root){
        
        if(root == NULL){
            return make_pair(0,0);
        }
        
        pair<int, int> left = solve(root -> left);
        pair<int, int> right = solve(root -> right);
        
        // yo node line ho bhane left ra right node ka na lida ko max value uthauna paiyo.
        int take = root -> data + left.second + right.second;
        
        // yo node na line ho bhane, you can decide if you want to take left wala node or
        // right wala node or decline both, 4 ota values chan, max(first, second) lida bho each ko lagi.
        int notTake = max(left.first, left.second) + max(right.first, right.second);
        
        return make_pair(take, notTake);
        
    }

    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int, int> status = solve(root);
        return max(status.first, status.second);

    }
};
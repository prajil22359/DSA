#include <iostream>
using namespace std;
#include <vector>


struct Node
{
    int data;
    Node* left, * right;
};


class Solution
{
public:


    void solve(Node* root, int nodeCount, int sum, pair<int, int> &ans){
        
        if(root == NULL){
            
            // tracking best answer
            if(nodeCount > ans.first){
                ans.first = nodeCount;
                ans.second = sum;
            }
            else if(nodeCount == ans.first){
                ans.second = max(sum, ans.second);
            }
            return;
        }

        solve(root -> left, nodeCount +1, sum + root -> data, ans);

        solve(root -> right, nodeCount +1, sum + root -> data, ans);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        pair<int, int> ans;
        
        if(root == NULL)    return 0;
        
        solve(root, 0, 0, ans);
        return ans.second;
    }
    
    
};
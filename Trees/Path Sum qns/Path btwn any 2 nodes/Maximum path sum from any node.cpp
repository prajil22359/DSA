#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};


class Solution{
  public:
  
    int maxPathDown(Node* root, int &maxi){
        
        if(root == NULL){
            return 0;
        }
        
        // left ya right max nai negative bahe ta tyo bhanda ramro na line 0.
        int leftMax = max(0, maxPathDown(root -> left, maxi));
        int rightMax = max(0, maxPathDown(root -> right, maxi));

        // this ans is what we are tracking.. 
        int ans = root -> data + leftMax + rightMax;
        maxi = max(maxi, ans);

        // returning value is kinda height so ... this + either left or right..
        return root -> data + max(leftMax, rightMax);
    }
  
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        int maxi = -1e9;
        
        // maxPathDown from a node bata maxPathSum nikalna sakincha. 
        // just like we found longest path b/w any two nodes :-> the diameter problem or
        // in these terms maxPathSum with node value 1. using the height algo: 
        // whats height: maxPathDown with node value 1.
        maxPathDown(root, maxi);
        return maxi;
    }
};

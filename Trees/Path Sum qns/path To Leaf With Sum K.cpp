
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
  public:

    int solve(Node* root, int k, int sum){

        if(root == NULL) return 0; // what if initially its given null -> return 0;
        sum += root -> data;

        // its the leaf node, the path's last node, checking if the sum == k in this path.
        if(root -> left == NULL && root -> right == NULL){
            if(sum == k) return 1;
            else return 0;
        }

        int left = 0;
        int right = 0;
        if(root -> left){
            left = solve(root -> left, k, sum );
        }
        if(root -> right){
            right = solve(root -> right, k, sum );
        }

        return left + right;
    }

    int pathToLeafWithSumK(Node *root,int k)
    {
        return solve(root, k, 0);
    }
};


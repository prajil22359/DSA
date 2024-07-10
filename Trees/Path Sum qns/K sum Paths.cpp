// count all paths which have sum k. 
// A path may start from any node and end at any node in the downward direction.
// single node bhi chalega. root to leaf ko kunai path ko sabai subarray path hun.

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

    void solve(Node *root, int k, int &count, vector<int> &path){

        if(root == NULL){
            return;
        }

        path.push_back(root -> data);
        solve(root -> left, k, count, path);
        solve(root -> right, k, count, path);

        int sum = 0;
        for(int i = path.size()-1; i >= 0; i--){
            sum += path[i];
            if(sum == k) count++;
        }
        path.pop_back();

    }


    int sumK(Node *root,int k)
    {
        int count = 0;
        vector<int> path;
        solve(root, k, count, path);
        return count;
    }
};
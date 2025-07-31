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

// CLEVER BUT NOT FULLY OPTIMIZED
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


// OPTIMIZED APPROACH O(N)
class Solution {
    int answer = 0;
    unordered_map<int,int> count;  // prefixSum → frequency

public:
    int pathSum(TreeNode* root, int K) {
        count[0] = 1;            // “empty” prefix has sum 0 once
        dfs(root, 0, K);
        return answer;
    }

private:
    void dfs(TreeNode* node, int currSum, int K) {
        if (!node) return;

        // 1) Update current sum
        currSum += node->val;

        // 2) Count paths ending here with sum K
        //    That means some earlier prefixSum = currSum - K
        if (count.count(currSum - K))
            answer += count[currSum - K];

        // 3) Include this prefixSum for children
        count[currSum]++;

        // 4) Recurse down
        dfs(node->left,  currSum, K);
        dfs(node->right, currSum, K);

        // 5) Backtrack: remove this prefix before returning
        count[currSum]--;
    }
};

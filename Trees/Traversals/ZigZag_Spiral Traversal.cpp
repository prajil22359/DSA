#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

// Definition for a binary tree node.
 struct TreeNode {
    int val;  
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> queue1; 

        bool leftToRight = true;
        if(root) queue1.push(root);
        vector<vector<int>> ans;


        while (!queue1.empty()){
            int count = queue1.size();
            vector<int> temp;
            for(int i = 0; i < count; i++){
                TreeNode* front = queue1.front();
                queue1.pop();
                temp.push_back(front->val);

                if(front-> left){
                    queue1.push(front ->left);
                }
                if(front-> right) {
                    queue1.push(front ->right);
                }
            }
            if(leftToRight){
                ans.push_back(temp);
            }
            else{
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            leftToRight = !leftToRight;
        }

        return ans;
    }
};

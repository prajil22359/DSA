#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Definition for a binary tree node.
 struct TreeNode {
    int val;  
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// level wise elements halera de bhaneko cha. simple bfs nai garne ho, tara level differentiate
// garna ya ta euta null marker add garne tarika cha, else count wala tarika.

// BELOW IS THE COUNT TARIKA : bujhauna sakiraha chuina her ekchoti, kasari duita loop lagai khel
// gareko cha.

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue1; 

        if(root == NULL) return {}; // important, root null bhako case ma ans khali jancha.

        queue1.push(root); 

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
            ans.push_back(temp);
        }

        return ans;
    }
};
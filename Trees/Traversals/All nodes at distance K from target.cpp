#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

// Definition for a binary tree node.
 struct TreeNode {
    int val;  
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:

    // hami tala ta khoji halchau tree ma tara mathi jana sakdainau: just convert this tree to a graph.
    // make parent pointers and then apply bfs, distance k from target hamro ans hunchan -> layer k wala
    // elements hun ans..

    map<TreeNode*, TreeNode*> buildParent(TreeNode* root){
        queue<TreeNode* > queue1;
        map<TreeNode*, TreeNode*> parent;

        queue1.push(root);
        parent[root] = NULL;

        while(!queue1.empty()){
            TreeNode* node = queue1.front();
            queue1.pop();

            if(node -> left){
                queue1.push(node -> left);
                parent[node -> left] = node;
            }
            if(node -> right){
                queue1.push(node -> right);
                parent[node -> right] = node;
            }
        }
        return parent;
    }



    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> parent = buildParent(root);

        // bfs traversal.
        queue <TreeNode* > queue1;
        queue1.push(target);

        map<TreeNode*, bool> visited;
        visited[target] = true;

        if(k == 0){
            return {target -> val};
        }

        while(!queue1.empty()){
            int count = queue1.size();
           
           for(int i = 0; i < count; i++){
                
                TreeNode* node = queue1.front();
                queue1.pop();

                if(node -> left && !visited[node -> left]){
                    queue1.push(node -> left);
                    visited[node -> left] = true;
                }
                if(node -> right && !visited[node -> right]){
                    queue1.push(node -> right);
                    visited[node -> right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    queue1.push(parent[node]);
                    visited[parent[node]] = true;
                }
           }
           k --;

           if(k == 0){
            break;
           }
        }

        vector<int> ans;
        while(!queue1.empty()){
            ans.push_back(queue1.front() ->val);
            queue1.pop();
        }


        return ans;
    }
};
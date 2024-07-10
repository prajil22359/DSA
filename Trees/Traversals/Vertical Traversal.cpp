#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

// Definition for a binary tree node.
 struct TreeNode {
    int val;  
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

// vertical traversal: 
// traversal kasto ho yo: leftmost column dekhi right most jane. column ma mathi dekhi tala jane.
// eutai horizontal distance ra level ma euta bhanda badi element chan bhane qn wise deal huncha,
// jasto yaha tyasto pare sorted order ma rakh bhanyo.

// data structure bananu parne matrai ho: map1[hd][lvl] maps to a vector of nodes in that hd and
// lvl. yo banae ans bhetihalyo. queue use gari bfs traversal garim: level is one plus to its parent
// and horizontal distance decreases for leftchild and increaes for right child.


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> map1;

        // level order traverse gar.
        vector<vector<int>> ans;

        if(root == NULL){
            return ans;
        }

        queue<pair<TreeNode*, pair<int, int>>> queue1;
        queue1.push(make_pair(root, make_pair(0, 0)));

        while(!queue1.empty()){
            
            pair<TreeNode*, pair<int, int>> front = queue1.front();
            queue1.pop();

            TreeNode* frontNode = front.first;
            int hd = front.second.first;
            int lvl = front.second.second;

            map1[hd][lvl].push_back(frontNode -> val);

            if(frontNode -> left){
                queue1.push(make_pair(frontNode -> left, make_pair(hd - 1, lvl + 1 )));
            }

            if(frontNode -> right){
                queue1.push(make_pair(frontNode -> right, make_pair(hd + 1, lvl + 1 )));
            }
        }

        for(pair<int, map<int, vector<int>>> i : map1){
            vector<int> temp;
            for(pair<int, vector<int>> j : i.second){
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    
    }
};
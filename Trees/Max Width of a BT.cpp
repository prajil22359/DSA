#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:

// PADH EKCHOTI BUJHCHAS SOLVE GARNU GARO THIYENA, SCALE GARNA DIMAG LAGAUNU PARCHA.

// In a full binary tree, the index calculation of left child and right child is:
// left child index = parent index * 2 + 1
// right child index = parent index * 2 + 2

// So the basic idea is to use a queue to traverse the tree level by level, and record the 
// difference between the most left node's index and the most right node's index, and update 
// the max index distance for each layer.

// The problem is, even with a tree with only 3000 nodes, the index difference may overflow 
// in a int32 integer (up to 2^3000 when all the nodes are on a parent-child chain). 
// To address this problem, one way is to use long long type. But it's not easy to scale up to 
// a tree with more nodes. Note that the absolute value of a node's index is not important. 
// What matters is the distance from the left most node to the right most node. So for each layer,
// we can reduce the index value by starting the left most node's index from 0. With this second
// approach, we can handle a tree up to 2,147,483,647 layers just with int32 type.

    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long long>> queue1;

        queue1.push(make_pair(root,0));
        long long maxi = 0;

        while(!queue1.empty()){
            int count = queue1.size();
            long long first = queue1.front().second; // first index of this level
            
            long long offset = first;
            first = 0;

            long long last; // last index of this level.

            for(int i = 0; i < count; i++){
                TreeNode* frontNode = queue1.front().first;
                long long index = queue1.front().second;

                last = queue1.front().second - offset;

                if(frontNode -> left) queue1.push(make_pair(frontNode -> left, 2*last));
                if(frontNode -> right) queue1.push(make_pair(frontNode -> right, 2*last + 1));
                
                queue1.pop();
            }
            maxi = max(maxi, (last - first) + 1);
            
        }
        return (int)maxi ;

    }
};
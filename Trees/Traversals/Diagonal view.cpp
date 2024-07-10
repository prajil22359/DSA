#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

struct Node
{
    int data;
    Node* left, * right;
};


void solve(Node* root, int layer,  map<int, vector<int>> &map1 ){
    
    if(root == NULL)    return;
    
    map1[layer].push_back(root -> data);
    
    if(root -> left) solve(root -> left, layer + 1, map1);
    if(root -> right) solve(root -> right, layer, map1);
    
}

vector<int> recursiveWay(Node* root){
   map<int, vector<int>> map1;
   int layer = 0; 
   solve(root, layer, map1);
   vector<int> ans;
   for(auto i : map1){
       for(auto j : i.second){
            ans.push_back(j);
       }
   }
   return ans;
}


vector<int> queueMethod(Node* root){
    queue<Node* > queue1;
    vector<int> ans;
    if(root == NULL) return ans;

    queue1.push(root);

    while(!queue1.empty()){
        Node* frontNode = queue1.front();
        while(frontNode != NULL){
            ans.push_back(frontNode->data);
            if(frontNode -> left){
                queue1.push(frontNode -> left);
            }
 
            frontNode = frontNode -> right;
            
        }
        queue1.pop();
    }
    return ans;
}

vector<int> diagonal(Node *root)
{
    // return recursiveWay(root);
    return queueMethod(root);
}
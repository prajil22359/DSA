// left view kasari nikalne : harek level ko pahilo element. mathi dekhi tala print garide
// level order bata garna sakiyo. line by line level order nikalna aucha ni, euta level ko pahilo
// element haldai hamro ans bancha. done this way, in right view.

// Arko tarika is the recursive way. recursively depth first search gar tree ma. As soon as you 
// get a new level, store it in ans. 

// track garnu paryo level hai.

#include <iostream>>
using namespace std;
#include <vector>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void solve(Node*root, int lvl, vector<int> &ans){

    if(root == NULL){
        return;
    }

    // its a new level, level 0 for root so, the condition works
    if(lvl == ans.size()){ 
        ans.push_back(root -> data);
    }

    solve(root -> left, lvl+1, ans);
    solve(root -> right, lvl+1, ans);

}

vector<int> leftView(Node* root){
    
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}
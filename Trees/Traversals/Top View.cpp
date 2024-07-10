#include <iostream>>
using namespace std;
#include <map>
#include <vector>
#include <queue>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector<int> topView(Node* root){

    // bfs level order traversal
    // because of this, its certain that we will be taking smallest level first,
    // so no need to keep track of level

    queue<pair<Node*, int>> queue1;

    queue1.push(make_pair(root, 0));

    map<int, int> map1;

    while(!queue1.empty()){
        pair<Node*, int> front = queue1.front();
        queue1.pop();
        Node* frontNode = front.first;
        int hd = front.second;
        

        
        // there will be multiple nodes in one horizontal distance, I just need to pick
        // one, that doesnot mean I just keep a variable, it got overwritten by others.
        // so only if node for that hd exists in the map, take it.
        
        if(map1.count(hd) != 1)
            map1[hd] = frontNode->data;

        if(frontNode -> left) queue1.push(make_pair(frontNode -> left , hd - 1));
        if(frontNode -> right) queue1.push(make_pair(frontNode -> right , hd + 1));
    }
    
    vector<int> ans;
    for(auto i: map1){
        ans.push_back(i.second);
    }
    return ans;

}

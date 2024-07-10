#include <iostream>>
using namespace std;
#include <vector>
#include <queue>

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


// sabai level ko last element lidai ho. inner for loop k last element lai store gardai jane.
// recursive tarika ni cha, left view ma apply gareko chu

vector<int> rightView(Node*root){

    // level order tarversal gar
    queue<Node*> queue1;
    queue1.push(root);

    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    while (!queue1.empty()){
        int count = queue1.size();

        for(int i = 0; i < count; i++){
            Node*frontNode = queue1.front();
            queue1.pop();

            if(i == count-1){
                ans.push_back(frontNode -> data);
            }

            if(frontNode -> left) queue1.push(frontNode -> left);
            if(frontNode -> right) queue1.push(frontNode -> right);
        }
    }
    return ans;

}
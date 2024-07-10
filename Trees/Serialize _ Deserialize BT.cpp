#include <iostream>
using namespace std;
#include <queue>
#include <string>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        // level order ma rakhau
        queue<TreeNode*> queue1;
        

        string str = "";

        if(root){
            queue1.push(root);
        } 
        else{
            return str;
        }

        while(!queue1.empty()){
            TreeNode* frontNode = queue1.front();
            queue1.pop();

            if(frontNode != NULL){
                str += to_string(frontNode -> val);
                str += ",";
                queue1.push(frontNode -> left);
                queue1.push(frontNode -> right);
            }
            else{
                str += "#,";
            }
        }
        return str;
    }

    // Helper function to split a string by a delimiter
    vector<string> split(const string &s, char delimiter) {
        vector<string> tokens;
        string token;
        stringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        // Split the data into a vector of strings
        vector<string> nodes = split(data, ','); // wrote the split fn.

        // Create the root node
        TreeNode* root = new TreeNode(stoi(nodes[0])); // stoi is string to int typecast.
        queue<TreeNode*> q;
        q.push(root);

        // Index to keep track of the position in the vector
        int index = 1;

        // Use a queue to perform level-order reconstruction
        while (!q.empty() && index < nodes.size()) {
            TreeNode* node = q.front();
            q.pop();

            // Process the left child
            if (nodes[index] != "#") {
                node->left = new TreeNode(stoi(nodes[index]));
                q.push(node->left);
            }
            index++;

            // Ensure index is within bounds before processing the right child
            if (index < nodes.size() && nodes[index] != "#") {
                node->right = new TreeNode(stoi(nodes[index]));
                q.push(node->right);
            }
            index++;
        }

        return root;
            
        }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
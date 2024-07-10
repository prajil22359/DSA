#include <iostream>
using namespace std;

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

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    
    // harek node ko lagi left right switch garidena matrai. 
    // je left ma thyo tyo right ma rakh and conversely mirror tree banihalcha.
    // ek node ke liye mene kiya, baaki recursion karega.
    
    void mirror(Node* node) {
        
        if(node == NULL){
            return;
        }
        
        Node* temp = node -> right;
        node -> right = node -> left;
        node -> left = temp;
        
        mirror(node -> left);
        mirror(node -> right);
    }
};
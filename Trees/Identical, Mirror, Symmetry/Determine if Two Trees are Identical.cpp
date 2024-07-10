#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Easy, dubai trees identical hunu paryo. tree1 ko left/ right ya root ma jada je paincha
// tyahi tree2 ma ni paunu paryo.
   
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2 == NULL)    return true;
        if(r1 != NULL && r2 == NULL )   return false;
        if(r1 == NULL && r2 != NULL )   return false;
        
        // when neither is null.
        bool leftSubtreeIdentical = isIdentical(r1 -> left, r2 -> left);
        bool rightSubtreeIdentical = isIdentical(r1 -> right, r2 -> right);
        if(r1 -> data == r2 -> data &&  leftSubtreeIdentical == true && rightSubtreeIdentical == true){
                return true;
        }

        // if not then, false.
        return false;

    }
};


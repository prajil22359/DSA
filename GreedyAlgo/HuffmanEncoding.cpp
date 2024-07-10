// huffman codes nikalnu cha euta string ko. min frequency wala lai merge gardai jane ho using 
// min heap. huffman tree banaune ho, ani traverse it in preorder. traverse garda left jada string ma
// 0 add huncha bhnae right jada 1, leaf node pugepachi tyo code complete huncha

// huffman decoding:
// To find character corresponding to current bits, we use the following simple steps:
// 1. We start from the root and do the following until a leaf is found.
// 2. If the current bit is 0, we move to the left node of the tree.
// 3. If the bit is 1, we move to right node of the tree.
// 4. If during the traversal, we encounter a leaf node, we print the character of that particular
//    leaf node and then again continue the iteration of the encoded data starting from step 1.

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> 
#include <queue>

class Node{
    public: 
        int data;
        Node* left;
        Node* right;
        
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};


class cmp{
    public:
    bool operator()( Node* a, Node* b){
        return a -> data > b -> data;
    }
    
};

class Solution
{
	public:

        // preorder traversal le dincha all the codes.
	    void traverse(Node* root, vector<string> &ans, string temp){
	        // base case
	        if(root -> left == NULL && root -> right == NULL){
	            ans.push_back(temp);
	            return;
	        }
	   
    	    traverse( root -> left, ans, temp + '0');
    	    traverse(root -> right, ans, temp + '1');
	    
        }
	
	
		vector<string> huffmanCodes(string S,vector<int> f,int n)
		{
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    
		    for(int i = 0; i < n; i++){
		        Node* temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    while(pq.size() > 1){
		        
		        Node* left = pq.top();
		        pq.pop();
		        
		        Node* right = pq.top();
		        pq.pop();
		        
		        Node* newNode = new Node( left-> data + right-> data);
		        newNode -> left = left;
		        newNode -> right = right;
		        pq.push(newNode);
		    }
		    
		    Node* root = pq.top();
		    vector<string> ans;
		    string temp = "";
		    traverse (root, ans, temp);
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
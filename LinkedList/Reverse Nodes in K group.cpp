#include <iostream>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    
    ListNode *r = NULL;
    ListNode *q = NULL;
    ListNode *p = head;

    while ( p != NULL){
        r = q; 
        q = p;
        p = p -> next;
        q -> next = r;
    }
    head = q;
    return head;

}

ListNode* findKthNode(ListNode* faltu, int k){

    for(int i = 0; i < k-1; i++){ // kth node ma pugna first dekhi k-1 hidnu parcha
        if(faltu -> next != NULL)
            faltu = faltu -> next;
        else{
            return NULL;
        }
    }
    return faltu;

}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;


        while( temp != NULL){
            ListNode* kthNode = findKthNode(temp, k);

            if(kthNode == NULL){
                if(prevNode) prevNode -> next = temp;
                break;
            }
            nextNode = kthNode -> next;
            kthNode -> next = NULL;

            reverseList(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevNode -> next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;

    }
};
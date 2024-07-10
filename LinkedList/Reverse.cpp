#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // links reverse garnu cha: we use 3 sliding pointers. r -> q -> p
        // q ko next r garidine. bas reverse garidim linkedlist lai. p out of bound jada q last element ma huncha
        // tyasle second last lai point ta garinai sakeko hunhca. but since its the first node of the reversed 
        // linkedlist so pointing head there.
        
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
};
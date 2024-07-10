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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode *p = head;

        while (p != NULL){
            count++;
            p = p -> next; 
        }

        int elementToDelete = count - n + 1;

        // YOU have to handle deleteing or even inserting at first position differently

        if(elementToDelete == 1){  
            head = head -> next;
        }
        else{
            p = head;
            ListNode *q = NULL;

            for(int i = 1; i < elementToDelete; i++){
                q = p;
                p = p -> next;
            }

            if(p){
                q -> next = p -> next;
            }
        }
        return head;
    }
};
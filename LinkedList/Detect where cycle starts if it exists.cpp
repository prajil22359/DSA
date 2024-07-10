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

    // bruteforce using flag to keep track of already visited node
    ListNode* bruteForce(ListNode* head){
        ListNode* p = head;
        while(p != NULL){
            if(p -> val == -1e9){
                return p;
            }
            p -> val = -1e9;
            p = p -> next;
        }
        return NULL;
    }

    // Tortoise hare, slow fast pointer method
    ListNode* slowFastMethod(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;


    }

    ListNode *detectCycle(ListNode *head) {
        // return bruteForce(head);
        return slowFastMethod(head);
    }
};
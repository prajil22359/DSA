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

    ListNode* middleNode(ListNode* head) {
         
    // Initializing both fast and slow pointer to the head.
    ListNode *slow = head; 
    ListNode *fast = head; 

    while (fast != NULL && fast->next != NULL) { 
        // odd count huda fast-> next is null, even huda fast is null.
        // so it ends there, no out of bound operation.
        
        slow = slow->next;  // Move slow one step.
        fast = fast->next->next; // Move fast two steps.

    }

    // Return the slow pointer, which is now at the middle node.
    return slow; 
    }
};

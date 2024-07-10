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
    // else hash map ude garda ni bho.
    bool bruteForce(ListNode *head){
        ListNode* p = head;
        while(p != NULL){
            if(p -> val == -1e9){
                return true;
            }
            p -> val = -1e9;
            p = p -> next;
        }
        return false;
    }

    bool slowAndFastPointer(ListNode *head){
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow){
                return true;
            }
        }
        return false;
    }



    bool hasCycle(ListNode *head) {
        // return bruteforce(head);
        return slowAndFastPointer(head);
    }
};
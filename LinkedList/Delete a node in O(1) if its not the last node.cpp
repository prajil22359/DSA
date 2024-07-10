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

    // its only possible this way, if its not the last node, else you will need access of a predecessor.
    void deleteNode(ListNode* node) {
        ListNode* p = node;
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
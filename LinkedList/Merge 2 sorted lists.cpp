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

// pahila ma naya nodes banaudai thye, tyaso na garnu, tyahi nodes lai relink garnu.

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        // step 1 : dummy list bana
        ListNode* dummy = new ListNode;
        ListNode* current = dummy;

        while(list1 != NULL && list2 != NULL){

            if(list1 -> val < list2 -> val){
                current -> next = list1;
                list1 = list1 -> next;
            }
            else{
                current -> next = list2;
                list2 = list2 -> next;
            }

            current = current -> next;
        }

        // adding the remaining elements
        while(list1 != NULL){
            current -> next = list1;
            list1 = list1 -> next;
            current = current -> next;
        }

        while(list2 != NULL){
            current -> next = list2;
            list2 = list2 -> next;
            current = current -> next;
        }

        return dummy -> next;

    }
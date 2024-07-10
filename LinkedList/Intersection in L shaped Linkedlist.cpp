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

    // naively, check if the pointers traversing the two lists are equal at any point.
    ListNode *bruteForce(ListNode *headA, ListNode *headB){
        ListNode *p = headA;
        ListNode *q = headB;

        while (p != NULL){
            while(q != NULL){
                if(p == q){
                    return p;    
                }
                q = q -> next;
            }
            p = p -> next;
            q = headB;
        }
        return NULL;
    }

    // duita linkedlist cha, intersect garchan bhane pani tyo intersection portion at max smaller linked list
    // ko size ko huncha. So larger linkedlist ko agadi ko some portion ta intersction point hudai hoinan. Kati 
    // ta, the difference between the size of the two linkedlist. So bringing our pointer there for the larger
    // linkedlist and the other at the head of smaller linked list. Now we traverse simultaneously, if anytime
    // these two pointers are equal, there is an intersection, else not. 
    // tara yesari kasari chalcha. updated larger linkedlist ko ith position ra smaller linkedlist ko ith 
    // position ko pointer nai kina compare, aru sanga huna sakdaina ra? nai, kina bhane yesto huda, size of 
    // intersection alag alag huncha, visualize gar ekchoti, intersction portion ko size same, already linkedlist 
    // lai equal size ko garai sakim, then intersection ko agadi pani ta equal size nai huncha. 

    // aba garne duita tarika, 
    //    1. find sizes, traverse the difference in the larger ll keeping other pointer at head of smaller ll,  
    //       then simultaneously traverse both ll, and see if they are equal ever, if not no intersection.

    //    2. put both pointers at head of the ll, traverse together, when any of the pointer reach null, 
    //       place it at head of other ll, carry on traversing, if they dont meet return false, which is given 
    //       when both pointers are null at same time. gareko tyahi ho, code is concise bas


    ListNode *optimized(ListNode *headA, ListNode *headB){
        ListNode *l1 = headA;
        ListNode *l2 = headB;

        while (l1 != NULL || l2 != NULL){
            if(l1 == l2){
                return l1;
            }
            l1 = (l1 == NULL) ? headB : l1->next;
            l2 = (l2 == NULL) ? headA : l2->next;
        }
        return NULL;

    }



    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // return bruteForce(headA, headB);
        return optimized(headA, headB);
    }
        
};
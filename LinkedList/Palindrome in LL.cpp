#include <iostream>
using namespace std;
#include <stack>

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

    bool bruteForce(ListNode* head){
        // traverse and put all in stack, poppong them out, we get in reverse order. check as you traverse again.

        ListNode* temp = head;
        stack <int> stack1;

        while(temp != NULL){
            stack1.push(temp -> val);
            temp = temp -> next;
        }

        temp = head;

        while(temp != NULL){
            int a = stack1.top();
            stack1.pop();
            if(a != temp -> val){
                return false;
            }
            temp = temp -> next;
        }
        return true;
    }

    // middle element ma pugne tyaspachi ko linkedlist lai reverse garne. aba ta simply euta pointer head ma 
    // rakhne, arko yo revered portion ko starting dekhi, and compare one by one, if not equal at any instance,
    // its not a palindrome.

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

    bool spaceEfficient(ListNode* head){
        // divide the ll in two halfs. reverse the second half. first half and second half needs to be identical.


        ListNode* slow = head;
        ListNode* fast = head;

        // find middle. the middle is where second half begins : as we did earlier
        // its the second middle in even sized ll. 
        while (fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // this middle given by slow is where the second half begins

        // reverse the second half
        ListNode* temp2 = reverseList(slow);
        ListNode* temp1 = head;


        // we have the two halfs just see if they are equal in every index.
        while(temp2 != NULL){
            if(temp1 -> val != temp2 -> val){
                return false;
            }
            temp2 = temp2 -> next;
            temp1 = temp1 -> next;
        }
        return true;
    }

    // more efficient - store the first half elements in stack and traverse the next half comparing values with these popped ones.. 
    bool best(ListNode* head) {
            stack<int> st;
            ListNode* slow = head;
            ListNode* fast = head;
    
            // getting to middle of odd size ll and second middle of even sized..
            while (fast && fast->next) {
                st.push(slow->val);
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Skip middle element in case of odd-length
            if (fast) slow = slow->next;
    
            while (slow) {
                if (st.top() != slow->val) return false;
                st.pop();
                slow = slow->next;
            }
            return true;
    }


    bool isPalindrome(ListNode* head) {
        // return bruteForce(head);
        return spaceEfficient(head);
    }
};

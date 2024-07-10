#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// Merges two linked lists in a particular order based on the data value
// Use the same nodes, just relink them. Yesma hamile duita vertical ll lai merge gardai ho,
// so use bottom keyword. next is used for horizontal.

Node* merge(Node* list1, Node* list2){
    // Create a dummy node as a placeholder for the result
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    // Merge the lists based on data values
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->bottom = list1;
            list1 = list1->bottom;
        }
        else{
            res->bottom = list2;
            list2 = list2->bottom;
        }
        res = res -> bottom;
        res -> next = NULL;  // horizontal link lai empty gareko
    }

    // Connect the remaining
    // elements if any
    if(list1){
        res->bottom = list1;
    } else {
        res->bottom = list2;
    }

    // Break the last node's
    // link to prevent cycles
    if(dummyNode->bottom){
        dummyNode->bottom->next = NULL;
    }

    return dummyNode->bottom;
}

// Flattens a linked list with bottom pointers
Node* flatten(Node* head){

    // BASE CASE: If head is null or there is no next node, return head
    if(head == NULL || head->next == NULL){
        return head;
    }

    // Recursively flatten the rest of the linked list
    Node* mergedHead = flatten(head->next);
    head = merge(head, mergedHead);
    return head;
}



                                
                            

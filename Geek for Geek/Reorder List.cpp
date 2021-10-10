

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…

For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.



    ***********************************************************
*/


// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void reorderList(struct Node* head);

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    int t, n, m, i, x;

    cin >> t;
    while (t--) {
        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    }
    return 0;
}
// } Driver Code Ends


/* Following is the Linked list node structure */

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorderList(Node* head) {
     Node* h1 = head;
     Node* h2 = head->next;
     while(h2 != NULL && h2->next != NULL){
         h1 = h1->next;
         h2 = h2->next->next;
     }
     
     Node* p1 = head;
     Node* p2 = h1->next;
     h1->next=NULL;
         
     p2 = reverse(p2);
    //  cout << p2 ->data<<" "; 
     Node* root = new Node(0);
    //  cout << curr -> data<<" ";
     while(p2 || p1){
         if(p1!=NULL){
             root->next = p1;
             p1 = p1->next;
             root = root->next;
         }
        //  cout << root -> data<<" ";
         if(p2!=NULL){
             root->next = p2;
             p2 = p2->next;
             root = root->next;
         }
        //  cout << root -> data<<" \n";
     }
     head = root->next;
}
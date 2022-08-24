

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a doubly linked list which in addition to the next and previous pointers, 
it could have a child pointer, which may or may not point to a separate doubly linked list. 
These child lists may have one or more children of their own, 
and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. 
You are given the head of the first level of the list.



    ***********************************************************
*/


#include <bits/stdc++.h>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    void flaten(Node* root){
        if(root == NULL) return;
        Node* h = root;
        Node* c = root->child;
        Node* n = root->next;
        if(root->child){
            c->prev = root;   
            root->next = c;
            root->child = NULL;
            Node* ec = c;
            while(ec->next) ec=ec->next;
            if(n) {
                ec->next = n;
                n->prev = ec;
            }
        }
        flaten(root->next);
    }
    
    Node* flatten(Node* head) {
        flaten(head);
        return head;
    }
};
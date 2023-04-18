

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 


    ***********************************************************
*/


#include <bits/stdc++.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    void reverse(ListNode* &head)
    {
        // Initialize current, previous and next pointers
        ListNode* current = head;
        ListNode* prev = NULL, *next = NULL;
 
        while (current != NULL) {
           
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
    
    void cadd(ListNode* r1, ListNode* r2, int c, ListNode* root){
        if(r1 && r2){ root->val = (r2->val+r1->val + c)%10; root->next = new ListNode(); cadd(r1->next,r2->next,(r2->val+r1->val +c)/10, root->next); }
        else if(r1) { root->val = (r1->val +c)%10; root->next = new ListNode(); cadd(r1->next,r2,(r1->val +c)/10, root->next);}
        else if(r2) { root->val = (r2->val +c)%10; root->next = new ListNode(); cadd(r1,r2->next,(r2->val +c)/10, root->next);}
        else{
            root->val = c;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverse(l1);
        reverse(l2);
        ListNode* root = new ListNode();
        ListNode* temp = root;
        cadd(l1,l2,0,root);
        reverse(temp);
        if(temp && temp->val == 0) temp = temp->next;
        return temp;
        
    }
};
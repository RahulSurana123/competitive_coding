

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the 
kth node from the beginning and the kth node from the end (the list is 1-indexed).



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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int c = 0;
        ListNode* t1 = head;
        ListNode* t2 = head;
        ListNode* t3 = NULL;
        
        
        while(t1!=NULL){
            c++;
            if(c==k){
                t3 = t1;
            }
            if(c>k){
                t2 = t2->next;
            }
            t1 = t1->next;
        }
        if(t3 != NULL){
            int temp = t2->val;
            t2->val = t3->val;
            t3->val = temp;
        }
        return head;
    }
};
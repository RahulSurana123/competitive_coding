

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)



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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* t = head;
        ListNode* n = head->next;;
        while(t && n){
            int temp = t->val;
            t->val = n->val;
            n->val = temp;
            t = n->next;
            if(n->next)
            n = n->next->next;
        }
        return head;
    }
};
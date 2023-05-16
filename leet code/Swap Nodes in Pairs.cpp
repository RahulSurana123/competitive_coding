

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
        if(!head) return head;
        ListNode* t = new ListNode(-1);
        t->next = head;
        ListNode* r = t;
        ListNode* f = head;
        ListNode* s = head->next;
        while(s){
            ListNode* temp = t->next;
            t->next = f->next;
            f->next = s->next;
            s->next = temp;
            t = s->next;
            if(t)
            f = t->next;
            if(f)
            s = f->next;
            else break;
        }
        return r->next;
    }
};


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 


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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t = head;
        ListNode* n = head;
        while(t && n){
            while(n && t->val == n->val) n= n->next;
            t->next = n;
            t = t->next;
        }
        return head;
    }
};
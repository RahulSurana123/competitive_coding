

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a linked list, remove the nth node from the end of the list and return its head.


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 1;
        ListNode* cur = head;
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        while(cur){
            if(i>n) prev = prev->next;
            cur = cur->next;
            i++;
        }
        if(prev->val == -1) return head->next;
        if(prev->next)
        prev->next = prev->next->next;
        
        return head;
    }
};
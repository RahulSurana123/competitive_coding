

/* 

    Solution by Rahul Surana

    ***********************************************************

Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.



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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = new ListNode(-1);
        cur->next = head;
        ListNode* prev = cur,*curr = head; 
        while(curr != NULL){
            if(curr->val == val){
                prev->next = prev->next->next;
            }
            else{
                prev = prev->next;
            }
            curr = curr->next;
        }
        return cur->next;
    }
};
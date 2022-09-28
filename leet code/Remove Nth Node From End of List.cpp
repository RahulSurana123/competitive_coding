

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
        ListNode* temp = head;
        ListNode* rem = head;
        int i = 0;
        while(temp != NULL){
           
            temp = temp->next;
            if(i > n) rem = rem->next;
             i++;
        }
        if(rem == head && i <n+1){
            return head->next;
        }
        else{
            rem->next = rem->next->next; 
        }
        return head;
    }
};


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list. Return the linked list sorted as well.



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
        ListNode* temp = new ListNode(-1);
        ListNode* t = head;
        ListNode* prev = temp;
        while(t != NULL){
            bool f = false;
            if(t && t->next && t->val == t->next->val) { 
                while(t && t->next && t->val == t->next->val){
                    f = true;     
                    t = t->next; 
                }
                // cout << t->val <<" ";
                if(t->next == NULL) { f = false; t = NULL; }
            }
            if(!f){
                prev->next = t;
                prev = prev->next;
            }
            if(t) t = t->next;
            // if(!f){
            //     // cout << temp->val;
            // }
        }
        return temp->next;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.


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
    
    ListNode* reverse(ListNode* end){
        if(end == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* tail = end;
        ListNode* nexter = NULL;
        // cout << tail->val<<" <-";
        while(tail){
            
            nexter = tail->next;
            tail->next  = prev;
            prev = tail;
            tail = nexter;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* temp = new ListNode(-1);
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* end = slow->next;
        ListNode* start = head;
        slow->next = NULL;
        end = reverse(end);
        ListNode* ans = temp;
        while(end || start){
            if(start){
                temp->next = start;
                start = start->next;
                temp = temp->next;
            }
            if(end){
                temp->next = end;
                end = end->next;
                temp = temp->next;
            }
        }
        head = ans->next;
    }
};
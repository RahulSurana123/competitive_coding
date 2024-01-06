

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In a linked list of size n, where n is even, 
the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.


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

    ListNode* reverse(ListNode* &head){
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* tail = head;
        ListNode* nexter = NULL;
        while(tail){       
            nexter = tail->next;
            tail->next  = prev;
            prev = tail;
            tail = nexter;
        }
         return prev;
    }

    int pairSum(ListNode* head) {
        if(!head) return 0;
        ListNode* s = head, *f = head->next;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode* t1 = head;
        ListNode* t2 = reverse(s->next);
        int ans = 0;
        while(t1 && t2){
            ans = max(t1->val + t2->val, ans);
            t1 = t1->next;
            t2 = t2->next;
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* root = head->next;
        ListNode* x = root;
        ListNode* cur = head;
        while(cur && cur->next){
            cur->next = root->next;
            if(cur->next)
            cur = cur->next;
            else { cur->next = x; break; }
            root->next = cur->next;
            root = root->next;
            // cout << root->val <<" ";
        }
        if(cur == NULL) cur = x;
        else if(cur->next == NULL) cur->next = x;
        return head;
    }
};
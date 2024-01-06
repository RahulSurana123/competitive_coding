

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.


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

    void print(ListNode* &r){
        ListNode* t= r;
        while(t) {cout << t->val <<" -> "; t = t->next;}
        cout <<"\n";
    }

    ListNode* reverse(ListNode* &head, ListNode* &end){
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* tail = head;
        ListNode* nexter = NULL;
        while(tail != end){       
            nexter = tail->next;
            tail->next  = prev;
            prev = tail;
            tail = nexter;
        }
        head->next = end;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* &head, int k) {
        if(!head || !head->next) return head;
        ListNode* t1 = head;
        ListNode* t2 = head;
        ListNode* r = NULL;
        ListNode* prev = head, *np = NULL;
        int c = 1;
        while(t2){
            while(c < k){
                t2 = t2->next;
                if(!t2) break;
                c++;
            }
            if(!t2) break;

            if(np) np->next = t2;
            t2 = t2->next; 
            np = prev;
            t1 = reverse(t1,t2);
            
            if(!r) r = t1;
            prev = t2;
    
            t1 = t2;
            c = 1;
        }
        return r;
    }
};


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a linked list, rotate the list to the right by k places.



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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        ListNode* prev = head;
        int x = 0;
        while(temp != NULL) { x++; temp = temp->next; }
        temp = head;
        k = k%x;
        int a = 0;
        while(temp->next != NULL){
            if(a>=k) prev = prev->next;
            temp = temp->next;
            a++;
        }
        temp->next = head;
        temp = prev->next;
        ListNode* t = temp;
        // while(t->next == NULL) t = t->next;
        // t->next = head;
        prev->next = NULL;
        return temp;
    }
};
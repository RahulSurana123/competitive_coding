

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a linked list, return the list after sorting it in ascending order.



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
    
//     ListNode* quicksort(ListNode* s, ListNode* e,ListNode* head){
//         while(s<e){
            
//         }
//     }
    
    
    ListNode* sortList(ListNode* head) {
        vector<int> s;
        ListNode* temp = head;
        while(temp != NULL){
            s.push_back(temp->val);
            temp = temp->next;
        }
        sort(s.begin(),s.end());
        temp = head;
        for(auto x: s){
            temp->val = x;
            temp = temp->next;
        }
        return head;
    }
};
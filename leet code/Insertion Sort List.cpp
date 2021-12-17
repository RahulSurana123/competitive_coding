

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. 
One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL){
            ListNode* trav = head;
            int x = temp->val;
            // cout << x <<"->";
            while(trav != NULL && trav != temp->next){
                if(trav->val < temp->val){
                    trav = trav->next;
                }
                else {
                    int z = trav->val;
                    trav->val = x;
                    x = z;
                    trav = trav->next;
                }
            }
            temp = temp->next;
        }
        return head;
    }
};
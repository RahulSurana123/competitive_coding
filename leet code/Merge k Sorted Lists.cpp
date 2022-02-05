

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



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
    ListNode* merge(ListNode* first, ListNode* second)
    {
        ListNode* result = NULL;
        
        if(first == nullptr)
            return second;
        
        if(second == nullptr)
            return first;
        
        
        if(first -> val <= second -> val)
        {
            result = first;
            result -> next = merge(first -> next, second);
        }
        else
        {
            result = second;
            result -> next = merge(first, second -> next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        int k = arr.size(); // extracting size of array
        if(k == 0) // if size of array is value
            return NULL;
        
        int start = 0; // start pointer
        int last = k -1; // last pointer
        int temp;
        while(last != 0) // if last pointer not becomes zero
        {
            start = 0;
            temp = last;
            while(start < temp)
            {
                // merge them and store in one of the linked list
                arr[start] = merge(arr[start],arr[temp]);
                start++; // increment start
                temp--; // decrese start
                
                if(start >= temp) // if at any point start passes the temp
                {
                    last = temp;
                }
            }
        }
        return arr[0]; // return first linked list of the aray as now it contains the all nodes in the sorted order.
        
    }
};
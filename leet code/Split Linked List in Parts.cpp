

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. 
This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should 
always have a size greater than or equal to parts occurring later.

Return an array of the k parts.


    ***********************************************************
*/


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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* x = head;
        while(x!= NULL) {
            x = x->next; 
            n++;
        }
        int per = n/k;
        int rem = n %k;
        
        vector<ListNode*> ans(k,NULL);
        x = head;
        int c = 0, i = 0;
        while(x!= NULL){
            ans[i] = (x);
            while(x && c < (per+(rem>0))-1) { x = x->next; c++; }
            if(x){
                ListNode* z = x->next;    
                x->next = NULL;
                x = z;
            }
            rem--;
            c = 0;
            i++;
        }
        return ans;
    }
};
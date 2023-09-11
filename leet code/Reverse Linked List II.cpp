

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a singly linked list and two integers left and right where left <= right, 
comreverse the nodes of the list from position left to position right, and return the reversed list.


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

    ListNode* rr(ListNode* root, ListNode* stop){
        if(root == stop) return root;
        ListNode* prev=NULL, *cur= root, *n = NULL;
        while(cur != stop){
            n = cur->next;
            cur->next = prev;
            prev = cur;
            cur = n;
        }
        if(n && root)
        root->next = n;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int n = 0;
        ListNode* t,*ps=NULL, *s=NULL,*e=NULL, *temp = new ListNode(-1000);
        temp->next = head;
        t = temp;
        while(t!=NULL){
            if(n==left-1) ps = t;
            if(n == left) s = t;
            if(n == right+1) { e = t; break; }
            n++;
            t = t->next;
      
        } 
        if(ps) ps->next = rr(s,e);
        else temp->next = rr(s,e);
        return temp->next;
    }
};
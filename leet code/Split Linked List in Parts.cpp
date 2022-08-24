

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
        int count = 0;
        ListNode* it = head;
        while(it != nullptr){
            count++;
            it = it->next;
        }
        int size = floor(((double)count/(double)k));
        int extra  = count - (size *k);
        cout << size <<" "<<extra << "\n";
        vector<ListNode*> ans(k,nullptr);
        ListNode* iter = head;
        int i = 0;
        int n = 0;
        while(iter != nullptr){
            ListNode* tempHead = new ListNode(iter->val,nullptr);
            iter = iter->next;
            ans[n++] = tempHead;
            i=1;
            while(i < size){
                ListNode* temp = new ListNode(iter->val,nullptr);
                tempHead-> next = temp;
                tempHead = tempHead-> next;
                iter = iter->next;
              
                // cout << tempHead->val <<" " <<i << "\n";
                i++;
            }
            if(extra > 0 && i == size){
                ListNode* temp = new ListNode(iter->val,nullptr);
                tempHead-> next = temp;
                tempHead = tempHead-> next;
                iter = iter->next;
                // cout << tempHead->val <<" " <<extra << "\n";
                extra--;
            }
        }
        return ans;
    }
};
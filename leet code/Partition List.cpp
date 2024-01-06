

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the head of a linked list and a value x, partition it such that all nodes less than x come 
before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.


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
/* for printing output
    void pp(ListNode* x){
        ListNode* a = x;
        while(a){
            cout << a->val<<" ";
            a = a->next;
        }
        cout <<"\n";
    }
*/
    ListNode* partition(ListNode* head, int x) {
        ListNode* t1 = head, * t2 = head;
        while(t2 != NULL){
            if(t2->val >= x){
                t2 = t2->next;
            }
            else{
                int temp = t1->val;
                ListNode* t3 = t1;
                t1->val = t2->val;
                while(t3 && t3 != t2){
                    t3 = t3->next;
                    int temp2 = t3->val;
                    t3->val = temp;
                    temp = temp2;

                }
                t1 = t1->next;
                t2 = t2->next;
            }
        }
        return head;
    }
};
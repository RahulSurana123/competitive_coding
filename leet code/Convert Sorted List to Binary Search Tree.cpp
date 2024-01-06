
/*

Solution by Rahul Surana

    ***********************************************************


Given the head of a singly linked list where elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

 


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> x;

    TreeNode* df(int s, int e){
        if(s>e) return nullptr;
        if(s==e) return new TreeNode(x[s]);
        int m = ((s+e)>>1);
        TreeNode* root = new TreeNode(x[m]);
        root->left = df(s,m-1);
        root->right = df(m+1,e);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            x.push_back(head->val);
            head = head->next;
        }
        return df(0,x.size()-1);
    }
};
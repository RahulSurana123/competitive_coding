

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.



    ***********************************************************
*/


#include <bits/stdc++.h>

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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = root;
        if(root == NULL) return NULL;
        if(root->val == val) return ans;
        while(ans != NULL){
            if(ans->val > val){
                ans = ans->left;
            }
            else if(ans->val < val){
                ans = ans->right;
            }
            else return ans;
        }
        return NULL;
    }
};
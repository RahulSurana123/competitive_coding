

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary search tree (BST), where the values of exactly 
two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.



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
    
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void df(TreeNode* root){
        if(root == NULL) return;
        df(root->left);
        if(first == NULL && prev->val > root->val) first = prev;
        if(first != NULL && prev->val > root->val) second = root;
        prev = root;
        df(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        df(root);
        swap(first->val,second->val);
    }
};
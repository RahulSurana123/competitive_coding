

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



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

    bool df(TreeNode* &l,TreeNode* &r){
        if(!l && !r) return true;
        return l&&r&&(l->val == r->val) && df(l->left,r->right) && df(l->right,r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return df(root->left, root->right);
    }
};
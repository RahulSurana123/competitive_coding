

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a binary tree, determine if it is height-balanced.
 


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

    int th(TreeNode* root){
        if(!root) return 0;
        int r = th(root->right);
        int l = th(root->left);
        if(r == -1 || l == -1 || abs(l-r)>1) return -1;
        return 1 + max(r,l);
    };

    bool isBalanced(TreeNode* root) {
        if(th(root) == -1) return false;
        return true;
    }
};
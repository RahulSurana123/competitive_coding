

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

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

    int ans = 1e9;
    int prev = -1;

    void df(TreeNode* root){
        if(!root) return;
        df(root->left);
        if(prev != -1) ans = min(ans, root->val - prev);
        prev = root->val;       
        df(root->right);
    }

public:

    int getMinimumDifference(TreeNode* root) {
        df(root);
        return ans;
    }
};
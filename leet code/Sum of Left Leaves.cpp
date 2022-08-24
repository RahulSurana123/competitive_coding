

/* 

    Solution by Rahul Surana

    ***********************************************************

Given the root of a binary tree, return the sum of all left leaves.



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
    
    int sum(TreeNode* root,int d){
        if(root==NULL) return 0;
        if(!root->right && !root->left && d == 0) return root->val;
        int x = sum(root->left,0);
        int y = sum(root->right,1);
        return x+y;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root,-1);
    }
};
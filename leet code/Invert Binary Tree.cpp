

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, invert the tree, and return its root.



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
    
    void it(TreeNode* root){
        if(root == NULL) return;
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        root->left = right;
        root->right = left;
        it(root->left);
        it(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        it(root);
        return root;
    }
};
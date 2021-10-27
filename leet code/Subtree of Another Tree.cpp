

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the roots of two binary trees root and subRoot, return true 
if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. 
The tree tree could also be considered as a subtree of itself.



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
    
    
    bool isSub(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        return root->val == subRoot->val && isSub(root->left,subRoot->left) && isSub(root->right,subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return root == subRoot;
        if(subRoot == NULL) return true;
        return isSub(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
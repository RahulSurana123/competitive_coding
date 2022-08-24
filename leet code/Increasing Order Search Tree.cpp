

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary search tree, rearrange the tree in in-order so that 
the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only one right child.
 



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
    
    TreeNode* left = NULL;
    
    void df(TreeNode*& root, TreeNode* p){
        if(!p) return;
        df(root,p->left);
        root->right = new TreeNode(p->val);
        root = root->right;
        df(root,p->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp = new TreeNode();
        TreeNode* t1 = temp;
        df(temp,root);
        return t1->right;
    }
};
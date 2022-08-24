

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, 
is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.


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
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int l = 0, r = 0;
        TreeNode* left = root;
        TreeNode* right = root;
        while(left) { l++; left = left->left; }
        while(right) { r++; right = right->right; }
        if(l == r) return pow(2,l)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
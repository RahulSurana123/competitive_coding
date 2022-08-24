

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary tree. We install cameras on the tree nodes 
where each camera at a node can monitor its parent, itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.



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
    
    int ans = 0;
    
    int dfs(TreeNode* root){
        if(root == NULL) return 0;;
        if(root->left == NULL && root-> right == NULL) return -1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l == -1 || r == -1) { ans++; return 1; }
        if(l == 1 || r == 1) return 0;
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        int x = dfs(root);
        if(x==-1) ans++;
        return ans;
    }
};
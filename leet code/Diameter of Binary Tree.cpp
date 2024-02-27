

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



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
    
    int len(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        // if(root->left == NULL && root->right == NULL) return 1;
        int l = len(root->left,ans);
        int r = len(root->right,ans);        
        ans = max(ans,l+r);
        return max(l+1,r+1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        len(root,ans);
        return ans;
    }
};
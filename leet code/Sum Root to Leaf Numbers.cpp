

/* 

    Solution by Rahul Surana

    ***********************************************************

You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. 
Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.



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
    
    int out(TreeNode* root, int val){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return val;
        int ans = 0;
        if(root->left) ans += out(root->left,(val*10 + root->left->val));
        if(root->right) ans += out(root->right,(val*10 + root->right->val));
        // cout << ans <<"\n";
        return (ans);
    }
    
    int sumNumbers(TreeNode* root) {
        return out(root,root->val);
    }
};
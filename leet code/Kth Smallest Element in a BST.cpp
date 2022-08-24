

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 



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
    int z = 0;
    
    void df(TreeNode* root, int &k){
        if(root == NULL) return;
        df(root->left,k);
        k--;
        if(k == 0) z = root->val;
        df(root->right,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        df(root,k);
        return z;
    }
};
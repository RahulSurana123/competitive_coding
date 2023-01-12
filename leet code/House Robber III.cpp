

/* 
    Solution by Rahul Surana
    
    ***********************************************************


The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. 
It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.



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
    
    int df(TreeNode* root, int& l, int& r){
        if(root == NULL) return 0;
        int ans = 0;
        int ll=0,lr=0,rr=0,rl=0;
        l = df(root->left,ll,lr);
        r = df(root->right,rl,rr);
        return max(root->val+ll+lr+rl+rr,l+r);
    }
    
    int rob(TreeNode* root) {
        int l,r;
        return df(root,l,r);
    }
};
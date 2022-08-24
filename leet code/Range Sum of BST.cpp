

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root node of a binary search tree and two integers low and high, 
return the sum of values of all nodes with a value in the inclusive range [low, high].


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
    
    int df(TreeNode* root, int low, int high){
        if(root == NULL) return 0;
        int ans = (root->val >= low && root->val <= high ? root->val : 0);
        if(root-> left){
            ans += df(root->left, low, high);
        }
        if(root-> right){
            ans += df(root->right, low, high);
        }
        // cout << root->val << " "<< ans <<"\n";
        return ans;
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return df(root,low,high);
    }
};
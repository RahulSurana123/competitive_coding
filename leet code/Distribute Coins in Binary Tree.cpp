

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary tree with n nodes where each node in the tree has node.val coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the minimum number of moves required to make every node have exactly one coin.



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
        int l = 0, r= 0;
        if(root->left) l+=dfs(root->left);
        if(root->right) r+=dfs(root->right);
        ans += abs(root->val+l+r-1);
        return root->val+l+r-1;
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
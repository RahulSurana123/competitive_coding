

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
 


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
    // map<pair<TreeNode*,bool>,int> dp;
    int ans = 0;
    int df(TreeNode* &root, bool il){
        if(!root) return -1;
        int l = 1+df(root->left,false);;
        int r = 1+df(root->right,true);
        ans = max(ans,max(l,r));
        return max(l,r);
        // if(dp[{root,il}] != 0) return dp[{root,il}];
        // if(il) return dp[{root,il}] = 1+df(root->left,false);
        // else return dp[{root,il}] = 1+df(root->right,true);
    }
    
    int longestZigZag(TreeNode* root) {
        df(root,false),df(root,true);
        return ans;
        if(!root) return 0;
        return max(max(max(df(root,true), df(root,false)),longestZigZag(root->left)), longestZigZag(root->right));
    }
};
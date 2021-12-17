/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 


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
    
    TreeNode* build(vector<int> &nums, int s, int e){
        if(s>e) return NULL;
        if(s==e) return new TreeNode(nums[s]);
        int m = s + (e-s)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = build(nums,s,m-1);
        root->right = build(nums,m+1,e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = build(nums,0,nums.size()-1);
        return root;
    }
};
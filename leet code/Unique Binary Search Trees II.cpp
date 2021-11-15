

/* 

    Solution by Rahul Surana

    ***********************************************************

Given an integer n, return all the structurally unique BST's (binary search trees), 
which has exactly n nodes of unique values from 1 to n. Return the answer in any order.



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
    
    
    vector<TreeNode*> pos(int s, int e){
        
        if(s>e) { return {NULL}; }
        if(s==e) { return { new TreeNode(s) }; }
        vector<TreeNode*> ans;
        for(int i = s; i <= e; i++){
            vector<TreeNode*> l = pos(s,i-1);
            vector<TreeNode*> r = pos(i+1,e);
            for(auto left : l){
                for(auto right : r){
                    TreeNode* x = new TreeNode(i);
                    x->left = left;
                    x->right = right;
                    ans.push_back(x);
                }
            }
        }
        return ans;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return pos(1,n);
    }
};
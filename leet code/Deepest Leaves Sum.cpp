

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return the sum of values of its deepest leaves.



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
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int s = q.size();
            int c = 0;
            while(s--){
                auto x = q.front();
                q.pop();
                c += x->val;
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right); 
            }
            ans = c;
        }
        return ans;
    }
};
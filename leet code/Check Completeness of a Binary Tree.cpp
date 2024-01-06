

/* 

    Solution by Rahul Surana

    ***********************************************************

Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, 
and all nodes in the last level are as far left as possible. 
It can have between 1 and 2h nodes inclusive at the last level h.



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

    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool x = false;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto z = q.front();
                q.pop();
                if((z->right || z->left) && x) return false;
                if(z->right && !z->left) return false;
                if(!z->right || !z->left) { x = true; }
                if(z->left)
                q.push(z->left);
                if(z->right)
                q.push(z->right);
            }
        }
        return true;
    }
};
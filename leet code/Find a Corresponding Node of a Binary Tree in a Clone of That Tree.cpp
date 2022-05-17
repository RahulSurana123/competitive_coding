

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the 
target node and the answer must be a reference to a node in the cloned tree.



    ***********************************************************
*/



#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* ans;
    
    void df(TreeNode* o, TreeNode* c, TreeNode* t){
        if(o == NULL) return;
        if(o == t) { ans = c; return; }
        df(o->left,c->left,t);
        df(o->right,c->right,t);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        df(original,cloned,target);
        return ans;
    }
};
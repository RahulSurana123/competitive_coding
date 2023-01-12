

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| 
and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.



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

    int df(TreeNode* root, int mv, int miv){
        if(root == NULL) return 0;
        int ans = max(abs(mv - root->val), abs(miv-root->val));
        // cout << ans << " " << root->val <<" " << mv << "\n";
        if(root->left) ans = max(ans, df(root->left,max(mv,root->val),min(miv,root->val)));
        if(root->right) ans = max(ans, df(root->right,max(mv,root->val),min(miv,root->val)));
        return ans;
    }

    int maxAncestorDiff(TreeNode* root) {
        return df(root, root->val,root->val);
    }
};
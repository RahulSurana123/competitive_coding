

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree and an integer targetSum, 
return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 



    ***********************************************************
*/


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
    
   
    bool hasPathSum(TreeNode* root, int ts) {
        if(!root) return false;
        if(!root->left && !root->right) return ts == root->val;
        return hasPathSum(root->left,ts - root->val) || hasPathSum(root->right,ts - root->val) ;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.


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
    int ans=1e9;
    void df(TreeNode* root, int& l){
        if(root == NULL) return;
        df(root->left,l);
        ans = min(ans,root->val-l);
        l = root->val;
        df(root->right,l);
    }

    int minDiffInBST(TreeNode* root) {
        int x = -1e9;
        df(root,x);
        return ans;
    }
};


/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.


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
    int df(TreeNode* &root){
        if(root == NULL) return 100001;
        if(!root->left && !root->right) return 1;
        // if(root->left && !root->right) return 1 + minDepth(root->left) ;
        return 1 + min(df(root->right),df(root->left));
    }
    int minDepth(TreeNode* &root) {
        if(!root) return 0;
        return df(root);
    }
};
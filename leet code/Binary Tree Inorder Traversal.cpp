

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return the inorder traversal of its nodes' values.



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
    
    void df(TreeNode* root, vector<int> & ans){
        if(root == NULL) return;
        df(root->left,ans);
        ans.push_back(root->val);
        df(root->right,ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        df(root, ans);
        return ans;
    }
};
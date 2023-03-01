

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.



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

    vector<TreeNode*> ans;
    unordered_map<string, int> ad;

    string po(TreeNode* root){
        if(!root) return " ";
        string ls = po(root->left);
        string rs = po(root->right);
        string pos = to_string(root->val) +"("+ ls + rs+")";
        if(ad[pos]==1) ans.push_back(root);
        ad[pos]++;
        return pos;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        po(root);
        return ans;
    }
};
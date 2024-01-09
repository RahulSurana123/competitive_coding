

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Consider all the leaves of a binary tree, from left to right order, 
the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.



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

    string df(TreeNode* root){
        if(root == NULL) return "";
        if(!root->right && !root->left) return to_string(root->val)+"-";
        string ans = "";
        ans+=df(root->left);
        ans+=df(root->right);
        return ans;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string a = df(root1);
        string b = df(root2);
        // cout << a <<" "<< b<<"\n";
        return a==b;
    }
};
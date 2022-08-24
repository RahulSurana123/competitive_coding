


/* 

    Solution by Rahul Surana
    

    ***********************************************************


You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

        

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
    
    string ans = string(200,'z');
    
    void dfs(TreeNode* root, string b){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) { 
            reverse(b.begin(),b.end()); 
            if(ans> string(1,root->val +'a')+b) ans = string(1,root->val +'a')+b;
        }
        if(root->left) {
            dfs(root->left,b+string(1,root->val +'a'));
        }
        if(root->right) {
            dfs(root->right,b+string(1,root->val +'a'));
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        return ans;
    }
};
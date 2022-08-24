

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, 
return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.



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
    int p[101],l[101];
    
    void fc(TreeNode* root, int l1, int h){
        if(root == NULL) return;
        p[root->val] = h;
        l[root->val] = l1;
        fc(root->left,l1+1,root->val); 
        fc(root->right,l1+1,root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        fc(root,0,-1);
        return l[x] == l[y] &&  p[x] != p[y];
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, 
and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.



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
    
    TreeNode* build(vector<int> preorder,int& i, int s, int e){
        // cout << i << " " <<s << " "<< e <<"\n";
        if(s>e) { i-- ; return NULL; }
        if(s == e) return new TreeNode(preorder[i]);
        int ind = -1;
        for(int j = s; j <= e; j++){
            if(preorder[i]<preorder[j]){
                ind = j;
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        if(ind != -1) {
            root -> left = build(preorder,i,s+1,ind-1);
            i++;
        }
        else root -> left = build(preorder,i,s+1,e);
        
        if(ind != -1) 
            root -> right = build(preorder,i,ind,e);
        else root -> right = NULL;
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int i = 0;
        return build(preorder,i,0,n-1);
    }
};
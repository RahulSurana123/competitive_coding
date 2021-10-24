

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integer arrays preorder and inorder where preorder is the preorder traversal of 
a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



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
    
    TreeNode* build(vector<int> preorder, vector<int> inorder,int& i,int s,int e){
        if(s>e){
            i--;
            return NULL;
        }
        if(s==e){
            return new TreeNode(preorder[i]);
        }
        int ind = -1;
        for(int j = s; j <= e; j++){
            if(preorder[i] == inorder[j]){
                ind = j;
                break;
            }
        }
        TreeNode* root = new TreeNode(preorder[i]);
        i++;
        root -> left = build(preorder,inorder,i,s,ind-1);
        i++;
        root -> right = build(preorder,inorder,i,ind+1,e);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return build(preorder,inorder,i,0,preorder.size()-1);
    }
};
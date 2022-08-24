/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integer arrays inorder and postorder where inorder is the inorder 
traversal of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.


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


//  Not the most optimum solution


class Solution {
public:
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int& i, int s, int e){
        if(s>e){
            return NULL;
        }
        if(s==e) return new TreeNode(postorder[i--]);
        int ind;
        for(int j = s; j <= e; j++){
            if(postorder[i] == inorder[j]){
                ind = j;
                break;
            }
        }
        
        TreeNode* root = new TreeNode(postorder[i]);
        i--;
        cout << ind << " " << s <<" "<< e <<"\n"; 
        root->right = build(inorder,postorder,i,ind+1,e);
        root->left = build(inorder,postorder,i,s,ind-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int i = n-1;
        return build(inorder,postorder, i,0 ,n-1);
    }
};


// Best Solution 



class Solution {
public:
    map<int, int> m;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int& i, int s, int e){
        if(s > e) return NULL;
        int ind = m[postorder[i]];
        TreeNode* root = new TreeNode(inorder[ind]);
        i--;
        root->right = build(inorder,postorder,i,ind+1,e);
        root->left = build(inorder,postorder,i,s,ind-1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int j = 0; j <= n-1; j++){
            m[inorder[j]] = j;
        }
        int i = n-1;
        return build(inorder,postorder, i,0 ,n-1);
    }
};



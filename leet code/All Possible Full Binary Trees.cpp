

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer n, return a list of all possible full binary trees with n nodes. 
Each node of each tree in the answer must have Node.val == 0.

Each element of the answer is the root node of one possible tree. 
You may return the final list of trees in any order.

A full binary tree is a binary tree where each node has exactly 0 or 2 children.



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
    map<int,vector<TreeNode*>> m;
    
    vector<TreeNode*> aPFBT(int n) {
        if(n==1) return vector<TreeNode*>(1,new TreeNode(0));
        if(m.find(n) != m.end()) return m[n];
        vector<TreeNode*> ans;
        // if(n%2) return ans;
        for(int i = 1; i < n; i++){
            int l = i,r = n-1-i;    
            for(auto left : aPFBT(l)){
                for(auto right : aPFBT(r)){
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }   
            }
        }
        // m[n] = new vector(ans.begin(),ans.end());
        return m[n] = ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0) return vector<TreeNode*>();
        return aPFBT(n);
    }
};
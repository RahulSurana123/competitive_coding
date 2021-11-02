

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return the most frequent subtree sum. 
If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by 
the subtree rooted at that node (including the node itself).



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
    
    map<int, int> m;
    int ma = INT_MIN;
    
    int fs(TreeNode* root){
        if(root == NULL) return 0;
        int l = fs(root->left);
        int r = fs(root->right);
        m[l+r+root->val]++;
        if(m[l+r+root->val] > ma) ma = m[l+r+root->val];
        return l+r+root->val;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        fs(root);
        vector<int> ans;
        for(auto x: m){
            if(x.second == ma) ans.push_back(x.first);
        }
        return ans;
    }
};
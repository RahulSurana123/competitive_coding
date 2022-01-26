

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.


    ***********************************************************
*/


#include <bits/stdc++.h>
using namespace std;


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
    
    void df(TreeNode* root,vector<int> &s){
        if(root == NULL) return;
        df(root->left,s);
        s.push_back(root->val);
        df(root->right,s);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> s;
        df(root1,s);
        df(root2,s);
        sort(s.begin(),s.end());
        return s;
    }
};
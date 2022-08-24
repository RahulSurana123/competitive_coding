

/* 

    Solution by Rahul Surana
    

    ***********************************************************


We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.



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
    map<int,TreeNode*> m;
    void dfs(string s){
        int i = 0;
        string y = "0";
        while(i < s.length() && s[i] >= '0' && s[i] <= '9') y+=s[i++];
        int b = stoi(y);
        TreeNode* root = new TreeNode(b);
        m[0] = root;
        while(i < s.length()){
            int curr = 0;
            while(s[i++] == '-') {curr++;}
            i--;
            string x = "";
            while(i < s.length() && s[i] >= '0' && s[i] <= '9') x+=s[i++];
            int z = stoi(x);
            TreeNode* a = new TreeNode(z);
            // cout << curr <<" "<< z <<"\n";
            if( m[curr-1] && m[curr-1]->left != NULL) {
                m[curr-1]->right = a;
            }   
            else{
                m[curr-1]->left = a;
            }
            m[curr] = a;
        }
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        dfs(traversal);
        return m[0];
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.



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
    int ans = 0;

    int hfi(TreeNode* rt, int s){
        if(!rt) return 0;
        int l = hfi(rt->left,s);
        int r = hfi(rt->right,s);
        if(rt->val == s){ ans = max(l,r); return -1; }
        else if( l >= 0 && r >= 0){
            return max(l,r)+1;
        }
        ans = max(ans,abs(l)+abs(r));
        return min(l,r)-1;
    }

    int amountOfTime(TreeNode* root, int start) {
        hfi(root,start);
        return ans;
    }
};
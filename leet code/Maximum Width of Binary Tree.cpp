
/*


Solution By Rahul Surana


***********************************


Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.




*************************************/



#include<bits/stdc++.h>
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
   
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ans = 0;
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1ULL});
        while(!q.empty()){
            int s = q.size();
            ans = max(ans,q.back().second - q.front().second+1);
            while(s--){
                auto [x,y] = q.front();
                q.pop();
                if(!x) {  continue; }
                if(x->left)
                q.push({x->left,y*2+1});
                if(x->right)
                q.push({x->right,y*2+2});
            }
        }
        return ans;
    }
};
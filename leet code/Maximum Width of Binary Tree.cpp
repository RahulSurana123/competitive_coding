
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
        int ans = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1LL});
        while(!q.empty()){
            int s = q.size();
            int x = q.front().second;
            int z = q.back().second;
            ans = max(ans,z-x+1);
            cout << z <<" "<< x<<" ";
            while(s--){
                TreeNode* temp = q.front().first;
                long long i = q.front().second - x;
                q.pop();
                if(temp->left){
                    q.push({temp->left, (long long)(2*i)+1});
                }
                if(temp->right){
                    q.push({temp->right, (long long)(2*i) + 2});
                }
            }
        }
        return ans;
    }
};
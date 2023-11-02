/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

Given the root of a binary tree, 
return the number of nodes where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.

 

   
   ***********************************************************

*/

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

    pair<int,int> df(TreeNode* x){
        if(!x) return {0,0};
        auto [ls,lc] = df(x->left);
        auto [rs,rc] = df(x->right);
        if( (ls + rs + x->val)/(lc + rc + 1) == x->val ) ans++;
        return { ls + rs + x->val , lc + rc + 1 };
    }

    int averageOfSubtree(TreeNode* root) {
        df(root);
        return ans;
    }
};
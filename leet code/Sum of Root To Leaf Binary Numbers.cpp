



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.



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
    
    void df(TreeNode* root, int s){
        if(root == NULL){ return; }
        if(root->right == NULL && root->left == NULL) { s += root->val; cout << s <<" "; ans += s; return; }
        
        s += root->val;
        s *= 2;
        df(root->left,s);
        df(root->right,s);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        df(root,0);
        return ans;
    }
};
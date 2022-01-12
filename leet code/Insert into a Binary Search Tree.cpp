



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.


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
    
    void df(TreeNode* &root, int val){
        if(root == NULL) { root = new TreeNode(val); return; }
        if(root->left == NULL && root->right == NULL) { 
            if(root->val > val) root->left = new TreeNode(val); 
            else root->right = new TreeNode(val);
            return;
        }
        int x = root->val;
        if(val < x) { df(root->left,val); }
        else { df(root->right,val); }
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        df(root,val);
        return root;
    }
};
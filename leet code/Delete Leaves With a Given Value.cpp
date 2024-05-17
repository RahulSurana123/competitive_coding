

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, 
if its parent node becomes a leaf node and has the value target, 
it should also be deleted (you need to continue doing that until you cannot).


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

    bool df(TreeNode* r, int t){
        if(r==NULL) return true;
        if(r->left == NULL && r->right == NULL){
            return r->val == t;
        }
        bool a = df(r->left, t), b = df(r->right, t);
        if(a) r->left = NULL;
        if(b) r->right = NULL;
        return (a&&b) && r->val == t;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(df(root,target)) return NULL;
        return root;
    }
};
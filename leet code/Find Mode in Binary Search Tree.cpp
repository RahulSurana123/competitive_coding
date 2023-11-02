/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

Given the root of a binary search tree (BST) with duplicates, return all the mode(s) 
(i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.

 

   
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
    unordered_map<int,int> x;

    void df(TreeNode* r){
        if(!r) return ;
        x[r->val]++;
        df(r->left);
        df(r->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        df(root);
        vector<int> ans;
        int m = 0;
        for(auto a:x){
            m = max(m,a.second);
        }
        for(auto a:x){
            if(a.second==m) ans.push_back(a.first);
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. 
A leaf is a node with no children.



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
    
    vector<vector<int>> ans;
    
    void df(TreeNode* root, vector<int> &path, int sum,int tsum){
        if(root == NULL) return;
        path.push_back(root->val);
        sum += root->val;
        if(!root->right && !root->left){
            if(sum == tsum) ans.push_back(path);
        } 
        else{
            df(root->left,path,sum,tsum);
            df(root->right,path,sum,tsum);
        }
        path.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return ans; 
        vector<int> p;
        df(root,p,0,targetSum);
        return ans;
    }
};
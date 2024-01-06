

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
 


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push({root});
        int i = 0;
        while(!q.empty()){
            int s = q.size();
            vector<int> a;
            while(s--){
                auto x = q.front();
                q.pop();
                if(!x) continue;
                a.push_back(x->val);
                q.push(x->left);
                q.push(x->right);
            }
            if(i++%2) reverse(a.begin(),a.end());
            if(a.size()>0)
            ans.push_back(a);
        }
        return ans; 
    }
};
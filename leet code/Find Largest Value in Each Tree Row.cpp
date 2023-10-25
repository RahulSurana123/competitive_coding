/* 
   
   Solution by Rahul Surana
    
    ***********************************************************

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

   
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

static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };

    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int mx = INT_MIN;
            int s = q.size();
            while(s--){
                auto x = q.front();
                q.pop();
                mx = max(mx,x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            ans.push_back(mx);
        }   
        return ans;
    }
};
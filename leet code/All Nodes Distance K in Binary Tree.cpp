

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given the root of a binary tree, the value of a target node target, and an integer k, 
return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.


    ***********************************************************
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> m; 
    unordered_map<TreeNode*, bool> v;
    vector<int> ans;

    void df(TreeNode* &r, int k){
        if(r == NULL) return;
        if(v[r]) return;
        v[r] = true;
        // cout << r->val <<"\n";
        if(k == 0) {
            ans.push_back(r->val);
            return;
        }
        df(r->left,k-1);
        df(r->right,k-1);
        df(m[r],k-1);
    }

    void dfr(TreeNode* &r,  TreeNode* p){
        if(!r) return;
        m[r] = p;
        dfr(r->left,r);
        dfr(r->right,r);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfr(root,nullptr);
        df(target, k);
        return ans;
    }
};
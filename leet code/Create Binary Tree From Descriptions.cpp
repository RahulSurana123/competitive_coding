

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid.


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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        set<int> p;
        map<int,TreeNode*> vn;
        for(int  i = 0; i < d.size(); i++){
            if(!vn.count(d[i][0])) vn[d[i][0]] = new TreeNode(d[i][0]);
            if(!vn.count(d[i][1])) vn[d[i][1]] = new TreeNode(d[i][1]);
            if(d[i][2] == 1) vn[d[i][0]]->left = vn[d[i][1]];
            else vn[d[i][0]]->right = vn[d[i][1]];
            p.insert(d[i][1]);
        }
        for(auto x: d){
            if(!p.count(x[0])) return vn[x[0]];
        }
        return nullptr;
    }
};

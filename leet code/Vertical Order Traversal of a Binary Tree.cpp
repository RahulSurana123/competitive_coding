

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) 
and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting 
from the leftmost column and ending on the rightmost column. 
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.



    ***********************************************************
*/


#include <bits/stdc++.h>


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
    map<int,vector<pair<int,int>>> m;
    
    void t(TreeNode* root, int i){
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int l = 0;
        while(!q.empty()){
            int s = q.size();
            while(s--) {
                TreeNode* cur = q.front().first;
                int x = q.front().second;
                q.pop();
                if(cur == NULL) continue;
                cout << x <<" "<<cur->val<<"   ";
                if(m.find(x) == m.end()) m[x] = vector<pair<int,int>>();
                m[x].push_back({l,cur->val});
                q.push({cur->left,x-1});
                q.push({cur->right,x+1});
            }
            l++;
        }
        cout<<"\n";
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        t(root, 0);
        // sort(m.begin(),m.end());
        vector<vector<int>> ans(m.size(),vector<int>());
        int i = 0;
        for(auto x: m){
            sort(x.second.begin(),x.second.end());
    
            // sort(a.begin(),a.end());
            for(auto x1: x.second){
                ans[i].push_back(x1.second);
            }
            i++;
            // sort(ans[ans.size()-1].begin(),ans[ans.size()-1].end());
        }
        return ans;
    }
};
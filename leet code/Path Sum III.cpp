

/*

Solution by Rahul Surana

    ***********************************************************


Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


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
    int c = 0;
    unordered_map<int,int> z;
    
    void totalSum(TreeNode* root,int x,int targetsum){
        if(root == NULL) return;
        x += root->val;
        
        if(x == targetsum) c++;
        cout << targetsum <<" " <<x <<" " <<z[x-targetsum] << "\n";
        if(z.find(x-targetsum) != z.end()) c += z[x-targetsum];
        z[x]++;
        totalSum(root->left,x,targetsum);
        totalSum(root->right,x,targetsum);
        z[x]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        int i = 0;
        totalSum(root,i,targetSum);
        return c;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. 
The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, 
the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least 
a next number in the in-order traversal when next() is called.



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
class BSTIterator {
public:
    
    vector<TreeNode*> x;
    int i = 0;
    
    void df(TreeNode* root){
        if(root == NULL) return;
        df(root->left);
        x.push_back(root);
        df(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        df(root);
    }
    
    int next() {
        return x[i++]->val;
    }
    
    bool hasNext() {
        if(i>= x.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
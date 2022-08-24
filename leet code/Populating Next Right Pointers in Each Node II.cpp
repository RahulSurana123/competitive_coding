

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.



    ***********************************************************
*/



#include <bits/stdc++.h>

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            Node* prev = NULL;
            while(s--){
                auto x = q.front();
                q.pop();
                x->next = prev;
                prev = x;
                if(x->right) q.push(x->right);
                if(x->left) q.push(x->left);
            }
        }
        return root;
    }
};
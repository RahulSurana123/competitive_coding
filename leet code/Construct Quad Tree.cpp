

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a n * n matrix grid of 0's and 1's only. We want to represent the grid with a Quad-Tree.

Return the root of the Quad-Tree representing the grid.

Notice that you can assign the value of a node to True or False when isLeaf is False, 
and both are accepted in the answer.

A Quad-Tree is a tree data structure in which each internal node has exactly four children. 
Besides, each node has two attributes:

val: True if the node represents a grid of 1's or False if the node represents a grid of 0's.
isLeaf: True if the node is leaf node on the tree or False if the node has the four children.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;
}
We can construct a Quad-Tree from a two-dimensional area using the following steps:

If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and 
set val to the value of the grid and set the four children to Null and stop.
If the current grid has different values, set isLeaf to False and set val to any value 
and divide the current grid into four sub-grids as shown in the photo.
Recurse for each of the children with the proper sub-grid.

If you want to know more about the Quad-Tree, you can refer to the wiki.

Quad-Tree format:

The output represents the serialized format of a Quad-Tree using level order traversal, 
where null signifies a path terminator where no node exists below.

It is very similar to the serialization of the binary tree. The only difference is that 
the node is represented as a list [isLeaf, val].

If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and 
if the value of isLeaf or val is False we represent it as 0.



    ***********************************************************
*/


#include <bits/stdc++.h>

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
   
    Node* one = new Node(true,true);
    Node* zero = new Node(false,true);
    Node* df(vector<vector<int>> &a, int ir, int ic, int &on)
    {
        if(on == 0) return NULL;
        if(on == 1) {
            if(a[ir][ic]) return one;
            return zero;
        }        int hn = on/2;
        Node* tl = df(a,ir,ic,hn);
        Node* tr = df(a,ir,ic+hn,hn);
        Node* dl = df(a,ir+hn,ic,hn);
        Node* dr = df(a,ir+hn,ic+hn,hn);
        
        if( tl == tr && tr == dl && dl == dr){
            return tl;
        }
        return new Node(true, false, tl,tr,dl,dr);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return df(grid,0,0,n);
    }
};
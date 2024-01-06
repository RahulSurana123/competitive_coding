

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a tree (i.e. a connected, undirected graph that has no cycles) 
consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. 
The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels 
(i.e. The node with the number i has the label labels[i]).

The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.
 


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    vector<vector<int>> adj;
    vector<int> ans;
    vector<int> df(int x, string &label){
        vector<int> b(26,0);
        ans[x] = 1;
        for(auto z: adj[x]){
            if(ans[z]) continue;
            vector<int> a = df(z,label);
            for(int i = 0; i < 26; i++)
            b[i] += a[i];
        }
        b[label[x] - 'a']++;
        ans[x] = b[label[x]-'a'] ;
        return b;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        adj.resize(n,vector<int>());
        ans.resize(n,0);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        df(0,labels);  
        return ans;
    }
};
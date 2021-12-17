

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

Return a list of all MHTs' root labels. You can return the answer in any order.

The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.


    ***********************************************************
*/


#include <bits/stdc++.h>

#define F first
#define S second

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> in;
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        in.resize(n,0);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            in[e[0]]++;
            in[e[1]]++;
        }
        
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(in[i] == 1) q.push(i);
        }
        while(!q.empty()){
            ans.clear();
            int s = q.size();
            for(int i = 0; i < s; i++) {
                auto x = q.front();
                q.pop();
                ans.push_back(x);
                // if(v[x.F]) continue;
                // ans = max(ans,x);
                for(auto a: adj[x]){
                    in[a]--;
                    if(in[a] == 1) q.push(a);
                }
            }
        }
        if(ans.size() == 0) ans.push_back(0);
        return ans;
    }
};
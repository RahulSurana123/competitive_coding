

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is an undirected graph consisting of n nodes numbered from 0 to n - 1. 
You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node.

You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that 
there exists an undirected edge connecting nodes ai and bi.

A star graph is a subgraph of the given graph having a center node containing 0 or more neighbors. 
In other words, it is a subset of edges of the given graph such that there exists a common node for all edges.

The image below shows star graphs with 3 and 4 neighbors respectively, centered at the blue node.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:

    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n,vector<int>());
        for(auto &x: edges){
            adj[x[0]].emplace_back(x[1]);
            adj[x[1]].emplace_back(x[0]);
        }
        int ans = -1e9;
        for(int i = 0; i < n; i++){
            sort(adj[i].begin(),adj[i].end(),[&](int a, int b){ return vals[a]>vals[b]; });
            int sum = vals[i];
            for(int j = 0; j < adj[i].size(); j++){
                if(j >= k) break;
                if(vals[adj[i][j]] < 0) break;
                sum += vals[adj[i][j]];
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given the integer n and the array edges where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Return an array answer of length n where answer[i] is the sum of the distances between the ith node in the tree and all other nodes.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> adj;
    vector<int> size;  
    int ansR = 0;
    
    int data(int i, int p,int dept){
        ansR += dept;
        int ans = 1;
        for(int j = 0; j < adj[i].size(); j++ ){
            if(adj[i][j] != p)
            ans += (data(adj[i][j],i,dept+1));
        }
        return size[i] = ans;
    }
    
    void ac(vector<int>& ans,int i,int p){
        if(p != -1) ans[i] = ans[p] - size[i] + (ans.size() - size[i]);
        for(int j = 0; j < adj[i].size(); j++ ){
            if(adj[i][j] != p)
            ac(ans,adj[i][j],i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        adj.resize(n,vector<int>());
        size.resize(n,0);
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        data(0,-1,0);
        // for(int i = 0; i < n; i++){
        //     cout << size[i] <<" ";
        // }
        vector<int> ans(n);
        ans[0] = ansR;
        ac(ans,0,-1);
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections 
forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi.
Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    // vector<int> p;
    vector<vector<int>> adj;
    vector<int> low;
    vector<int> dis;
    vector<vector<int>> ans;
    int t = 1;
        
    void dfs(int u, int p){
        dis[u] = low[u] = t++;
        for (int next : adj[u]) {
            if (dis[next] == 0) {
                dfs(next, u);
                low[u] = min(low[u], low[next]);
            } else if (next != p)
                low[u] = min(low[u], dis[next]);
            if (low[next] > dis[u]) 
                ans.push_back({u, next});
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    
        // p.resize(n,-1);
        adj.resize(n);
        low.resize(n,0);
        dis.resize(n,0);
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0,-1);
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an undirected tree consisting of n vertices numbered from 0 to n-1, 
which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. 
Return the minimum time in seconds you have to spend to collect all apples in the tree, 
starting at vertex 0 and coming back to this vertex.

The edges of the undirected tree are given in the array edges, 
where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. 
Additionally, there is a boolean array hasApple, 
 hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

 


    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int ans = 0;

    bool df(int x, vector<vector<int>> &adj,vector<bool> &v, vector<bool>& hasApple){
        if(v[x]) return false;
        v[x] = true;
        //  cout << x <<" -> " <<" \n";
        for(auto z: adj[x]){
            if(df(z,adj,v,hasApple)){
                hasApple[x] = true;
            }
        }
        if(hasApple[x] && x!=0) ans+=2;
        return hasApple[x];
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> adj(n+1, vector<int>());
        vector<bool> v(n,false);
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        df(0,adj,v,hasApple);
        return  ans;
    }
};
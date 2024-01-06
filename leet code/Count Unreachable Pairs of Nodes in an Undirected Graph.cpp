

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. 
You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that 
there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.



    ***********************************************************
*/



#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> v;
    void df(int &i, long &c){
        if(v[i]) return;
        c++;
        v[i] = true;
        for(auto z: adj[i]){
            df(z,c);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n,vector<int>());
        v.resize(n,false);
        for(auto z: edges){
            adj[z[0]].push_back(z[1]);
            adj[z[1]].push_back(z[0]);
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            if(!v[i]){
                long a = 0;
                df(i,a);
                ans += (a * (n-a));
            }
        }
        return ans/2;
    }
};
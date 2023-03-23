

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming 
a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, 
and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.



    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> v; 
    void cc(int i){
        if(v[i]) return;
        v[i] = true;
        for(auto z: adj[i]){
            cc(z);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        adj.resize(n,vector<int>());
        v.resize(n,false);
        for(auto z: connections){
            adj[z[0]].push_back(z[1]);
            adj[z[1]].push_back(z[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!v[i]){
                cc(i);
                ans++;
            }
        }
        return ans-1;
    }
};
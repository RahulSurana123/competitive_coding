

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times 
as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, 
and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1); 
        // vector<int> v(n+1,0);
        vector<int> dist(n+1,1e9);
        for(vector<int> x: times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        // v[k] = 1;
        while(!q.empty()){
            pair<int,int> x = q.front();
            q.pop();
            dist[x.first] = min(dist[x.first],x.second);
            // if(v[x[0]]) continue;
            // v[x[0]] = 1;
            for(auto z: adj[x.first]){
                if(dist[z.first] > x.second + z.second)
                q.push({z.first, x.second + z.second});
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            // cout << i << " "<< dist[i] <<"\n";
            if(dist[i] == 1e9) return -1;
            ans = max(dist[i],ans);
        }
        return ans;
    }
};
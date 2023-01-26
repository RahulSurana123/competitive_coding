

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, 
return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<vector<int>>> adj(n,vector<vector<int>>());
        for(auto x: flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<vector<int>> q;
        vector<int> dist(n,1e9);
        q.push({src,0}); 
        while( k>=0 && !q.empty()){
            int s = q.size();
            while(s--){
                auto x = q.front();
                q.pop();
                for(auto z: adj[x[0]]){
                    if(dist[z[0]] < x[1]+z[1]) continue;
                    {
                        dist[z[0]] = x[1]+z[1];
                        q.push({z[0],x[1]+z[1]});
                    }
                }
            }
            k--;
        }
        return dist[dst] == 1e9? -1:dist[dst];
    }
};
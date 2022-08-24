

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
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        
        vector<int> v(n,1e9);
        v[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> V(v);
            for(auto x: f){
                v[x[1]] = min(v[x[1]], x[2]+V[x[0]]);
            }
        }
        return (v[dst]==1e9)?-1:v[dst];
    }
};
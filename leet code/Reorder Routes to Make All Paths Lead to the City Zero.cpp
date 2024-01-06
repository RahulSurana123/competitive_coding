

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). 
Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.

 


    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:

    vector<vector<pair<int,bool>>> adj;
    int ans = 0;
    void df(int &i, int &p){
        for(auto &[a,b]: adj[i]){
            if(a!=p){
                ans += b;
                df(a, i);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(auto &z: connections){
            adj[z[0]].push_back({z[1],true});
            adj[z[1]].push_back({z[0],false});
        }
        int a = 0,p = -1;
        df(a,p);
        return ans;
    }
};
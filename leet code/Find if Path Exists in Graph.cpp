

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, 
where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, 
return true if there is a valid path from source to destination, or false otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:

    int par(int a, vector<int> &p){
        if(a == p[a]) return a;
        return p[a] = par(p[a],p);
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> p(n+1);
        for(int i = 0; i <= n;i++){
            p[i] = i;
        }
        for(auto edge: edges){
            int a = par(edge[0],p);
            int b = par(edge[1],p);
            // cout << a <<" "<<b<<" "<< edge[0] <<" "<< edge[1]<<"\n";
            if(a==b) continue;
            p[a] = b;
        }
        return par(p[source],p) == par(p[destination],p);
    }
};
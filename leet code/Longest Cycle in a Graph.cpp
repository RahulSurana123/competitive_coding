

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a directed graph of n nodes numbered from 0 to n - 1, 
where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, 
indicating that there is a directed edge from node i to node edges[i]. 
If there is no outgoing edge from node i, then edges[i] == -1.

Return the length of the longest cycle in the graph. If no cycle exists, return -1.

A cycle is a path that starts and ends at the same node.

 


    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:
    
    vector<bool> v;
    int ans = -1;
    
    void df(int &i, vector<int>& edges,unordered_map<int,int> &dist){
        if(i == -1 || v[i]) {
           return;
        }
        v[i] = true;
        if(edges[i] != -1 && !v[edges[i]]){
            dist[edges[i]] = dist[i]+1; 
            df(edges[i],edges,dist);
        }
        else if(edges[i] != -1 && dist.count(edges[i])){
            ans = max(ans, dist[i] - dist[edges[i]]+1);
        }
        
    }

    int longestCycle(vector<int>& edges) {
        v.resize(edges.size(),false);
        for(int i = 0; i < edges.size(); i++){
            if(!v[i]){
                unordered_map<int,int> dist;
                dist[i] = 1;
                df(i, edges, dist);
            }
        }
        return ans;
    }
};
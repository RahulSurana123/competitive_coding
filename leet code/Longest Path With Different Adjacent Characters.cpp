



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. 
The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. 
Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to node i.

Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.

 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int ans = 0;
    vector<vector<int>> adj;

    int df(int x,string &s){
        if(adj[x].size() == 0) return 1;
        int a = 0,b = 0;
        for(int i = 0 ; i < adj[x].size(); i++){
            int l = df(adj[x][i],s);
            ans = max(ans,l);
            if(s[adj[x][i]] == s[x]) { continue;  }
            if(l> a){
                b = a;
                a = l;
            }
            else b = max(l,b);
        
        } 
        ans = max(a+b+1,ans);
        return a+1;
    }

    int longestPath(vector<int>& parent, string s) {
        adj.resize(s.length(),vector<int>());
        int f[parent.size()];
        memset(f,0,sizeof(f));
        for(int i = 1; i < parent.size(); i++){
            adj[parent[i]].push_back(i);
            f[parent[i]]++;
        }
        ans = 1;
        df(0,s);
        return ans;
    }
};
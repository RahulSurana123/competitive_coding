

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a directed acyclic graph, with n vertices numbered from 0 to n-1, 
and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. 
It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };

    vector<int> findSmallestSetOfVertices(int &n, vector<vector<int>>& edges) {
        
        vector<bool> v(n,false);
        for(auto &x : edges){
            v[x[1]] = true;
        }
        vector<int> ans;
        ans.reserve(n);
        for(int i = 0; i < n; i++){
            if(!v[i]) ans.push_back(i);
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. 
Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [ai, bi] indicates that there is a directed red edge from node ai to node bi in the graph, and
blueEdges[j] = [uj, vj] indicates that there is a directed blue edge from node uj to node vj in the graph.
Return an array answer of length n, 
where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, 
or -1 if such a path does not exist.



    ***********************************************************
*/


class Solution {
public:

    vector<vector<pair<int,bool>>> adj;
    map<pair<int,bool>,bool> vis;

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        adj.resize(n,vector<pair<int,bool>>());
        for(auto x: redEdges){
            adj[x[0]].push_back({x[1],false});
        }
        for(auto x: blueEdges){
            adj[x[0]].push_back({x[1],true});
        }
        vector<int> ans(n,-1);
        queue<pair<int,bool>> q;
        q.push({0, false});
        q.push({0, true});
        int s = 0;
        while(!q.empty()){
            int ss = q.size();
            while(ss--){
                auto x = q.front();
                q.pop();
                if(vis[{x.first,x.second}]) continue;
                vis[{x.first, x.second}] = true;
                if(ans[x.first] == -1) ans[x.first] = s;
                for(auto z: adj[x.first]){
                    if(!vis[{z.first,z.second}] && z.second != x.second){
                        q.push({z.first, z.second});
                    }
                }
            }
            s++;
        }
        return ans;
    }
};
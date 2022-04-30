

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] 
and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must 
find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero 
and that there is no contradiction.

 



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    map<string, vector<pair<string,double>>> adj;
    map<string,bool> vis;
    double ans;
    
    bool dfs(string s, string e, double a){
        if(s==e && adj.find(s) != adj.end()) { ans = a; return true; }
        
        // if(vis[s]) { vis[s] = false; return false; }
        vis[s] = true;
        bool k = false; 
        for(auto z : adj[s]){
            if(!vis[z.first]){
                if(dfs(z.first,e,a*z.second)) { k = true; }
                if(k) break;
            }
        }
        vis[s] = false;
        return k;
    }
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for(int i = 0 ; i < equations.size(); i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1/values[i]});
            vis[equations[i][0]] = false;
            vis[equations[i][1]] = false;
        }
        vector<double> ansQ;
        for(int i = 0 ;i < queries.size(); i++){
            if(dfs(queries[i][0],queries[i][1],1.0)){
                ansQ.push_back(ans);
            }
            else{
                ansQ.push_back(-1);
            }
        }
        return ansQ;
    }
};
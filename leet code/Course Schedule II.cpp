

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    stack<int> S;
    vector<int> V;
    vector<int> P;
    bool cycle;
    map<int, vector<int> > G;
    
    void DFS(int n)
    {        
        for(int i=0;i<n;++i)
        {
            if(!V[i]) DFS_recur(i);
        }
    }
    
    void DFS_recur(int curr)
    {
        if(cycle) return;
        
        V[curr] = true;
        P[curr] = true;
        
        for(int i : G[curr])
        {   
            if(P[i] == true) cycle = true;
            if(!V[i]) DFS_recur(i);
        }
        
        S.push(curr);
        P[curr] = false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> Ans;
        V.assign(n, false);
        P.assign(n, false);
        cycle = false;
        for(auto i : prerequisites)
        {
            G[i[1]].push_back(i[0]);
        }

        DFS(n);
        
        while(!S.empty())
        {
            Ans.push_back(S.top());
            S.pop();
        }
        
        if(cycle) return {};
        return Ans;
    }
};
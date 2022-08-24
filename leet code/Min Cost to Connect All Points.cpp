

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
|xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if 
there is exactly one simple path between any two points.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    int parent(int u, vector<int> &p){
        if(p[u] == u) return u;
        return p[u] = parent(p[p[u]],p);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int ans = 0,c = 0;
        priority_queue<pair<int,pair<int,int>>> pq;
        map<int,bool> vm;
        vector<int> p(points.size()+1,0);
        
        for(int i = 0 ; i < points.size(); i++){
            p[i] = i;
            for(int j = i+1 ; j < points.size(); j++){
                pq.push({-(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])),{i,j}});
            }   
        }
        while(c<points.size() && !pq.empty()){
            auto x = pq.top();
            pq.pop();
            int a = parent(x.second.first,p);
            int b = parent(x.second.second,p);
            if(a == b) continue;
            p[b] = a;
            c++;
            // cout << x.first << " " << x.second.first << " " << x.second.second <<"\n";
            ans -= x.first;
        }
        // cout <<"\n";
        return ans;
    }
};
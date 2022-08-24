

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n= grid[0].size();
        queue<pair<int,int>> q;
        set<pair<int,int>> s;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n ;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    s.insert({i,j});
                }
            }   
        }
        int ans=0;
        queue<pair<int,int>> nq;
        bool changed = false;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x > 0 && grid[x-1][y] == 1) { 
                grid[x-1][y] = 2; 
                s.erase({x-1,y}); 
                nq.push({x-1,y});
                changed = true;
            }
            if(x <m-1 && grid[x+1][y] == 1) { 
                grid[x+1][y] = 2; 
                s.erase({x+1,y}); 
                nq.push({x+1,y});
                changed = true;
            }
            if(y > 0 && grid[x][y-1] == 1) { 
                grid[x][y-1] = 2; 
                s.erase({x,y-1}); 
                nq.push({x,y-1});
                changed = true;
            }
            if(y < n-1 && grid[x][y+1] == 1) { 
                grid[x][y+1] = 2; 
                s.erase({x,y+1}); 
                nq.push({x,y+1});
                changed = true;
            }
            if(q.empty()){
                if(changed){
                    ans++;
                    swap(q,nq);
                    changed = false;
                }
                else break;
            }
            cout << ans <<" ";
        }
        if(s.size() > 0) return -1;
        return ans; 
    }
};
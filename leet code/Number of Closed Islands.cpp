

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a 2D grid consists of 0s (land) and 1s (water).  
An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    bool df(int i, int j,vector<vector<int>>& grid){
        if(i<0 || j <0 || i > grid.size()-1 || j > grid[0].size()-1) return false;
        if(grid[i][j]) return true;
        grid[i][j] = 1;
        bool r = df(i+1,j,grid), l =  df(i-1,j,grid), d = df(i,j+1,grid), u = df(i,j-1,grid);
        return ( r && l && d && u);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!grid[i][j]){
                    ans+= df(i,j,grid);
                }
            }   
        }
        return ans;
    }
};
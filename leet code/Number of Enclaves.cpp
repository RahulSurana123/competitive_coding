

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) 
land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any 
number of moves.



    ***********************************************************
*/



#include <bits/stdc++.h>


class Solution {
public:

    void df(int i, int j,vector<vector<int>>& grid){
        if(i<0 || j <0 || i > grid.size()-1 || j > grid[0].size()-1 || !grid[i][j]) return;
        grid[i][j] = 0;
        df(i+1,j,grid), df(i-1,j,grid),  df(i,j+1,grid), df(i,j-1,grid);
        // return ( r && l && d && u);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            df(i,0,grid);
            df(i,grid[0].size()-1,grid);   
        }
        for(int j = 0; j < grid[0].size(); j++){
            df(0,j,grid);
            df(grid.size()-1,j,grid);
        }
        for(auto &i: grid){
            for(auto &j: i){
                ans+=j;
            }
        }
        return ans;
    }
};
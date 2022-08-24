

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

In one shift operation:

Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        k = k%(grid.size()*grid[0].size());
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),0));
        int a = k/grid.size();
        int b = k%grid[0].size();
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                a = ((j+k)/grid[0].size());
                // cout <<(i+a)%grid.size() <<" "<< (j+k)%grid[0].size() <<"\n";
                ans[(i+a)%grid.size()][(j+k)%grid[0].size()] = grid[i][j];
            }
        }
        return ans;
    }
};
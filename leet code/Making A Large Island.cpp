

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    
    vector<vector<int>> colors,dp;
    
    int dfs(int i, int j, int n,vector<vector<int>>& grid, int color){
        if(i >= n || j >= n || i < 0 || j < 0 || colors[i][j] || grid[i][j] == 0) return 0;
        colors[i][j] = color;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        if(i < n-1 && grid[i+1][j] != 0) ans+= dfs(i+1,j,n,grid,color);
        if(j < n-1 && grid[i][j+1] != 0) ans+= dfs(i,j+1,n,grid,color);
        if(i > 0 && grid[i-1][j] != 0) ans+= dfs(i-1,j,n,grid,color);
        if(j > 0 && grid[i][j-1] != 0) ans+= dfs(i,j-1,n,grid,color);
        return dp[i][j] = ans;
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        colors.resize(n,vector<int>(n,0));
        dp.resize(n,vector<int>(n,-1));
        int color = 1;
        map<int,int> color_area_map;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    color_area_map.insert({color,dfs(i,j,n,grid,color)});
                    color++;
                }
                // cout << color_area_map[colors[i][j]] << " "<< colors[i][j] <<" ";
            }
            // cout << "\n";
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int m = 1;
                    set<int> groups;
                    for(auto x: dir){
                        int r = i+x[0];
                        int c = j+x[1];
                        if((!(r>=n || c >= n || r < 0 || c < 0) && colors[r][c] && groups.count(colors[r][c]) == 0)){
                                m += color_area_map[colors[r][c]];
                                groups.insert(colors[r][c]);
                        }
                    }
                    ans = max(ans,m);
                    // cout << ans <<" ";
                    // cout << "\n";
                }
            }
        }
        if(ans == 0 && grid[0][0] == 1) return n*n;
        return ans;
    }
};


/* 

    Solution by Rahul Surana

    ***********************************************************

You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int ans = 0,count1=1;
    
    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, int count){
        if(i<0||j<0||i>m-1||j>n-1|| grid[i][j] == -1) return;
        if(grid[i][j] == 2){
            if(count1 == count) ans++;
            return;
        }
        grid[i][j] = -1;
        if(i>0) dfs(i-1,j,m,n,grid,count+1);
        if(i<m-1) dfs(i+1,j,m,n,grid,count+1);
        if(j>0) dfs(i,j-1,m,n,grid,count+1);
        if(j<n-1) dfs(i,j+1,m,n,grid,count+1);
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int si = 0,sj = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    si = i;
                    sj = j;
                }
                else if(grid[i][j] == 0){
                    count1++;
                }
            }
        }
        dfs(si,sj,m,n,grid,0);
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 



    ***********************************************************
*/


#include<bits/stdc++.h>

class Solution {
public:
    // int ans = INT_MAX;
    vector<vector<int>> dp;
    vector<vector<int>> v;
    int df(int i, int j, int n, int m, vector<vector<int>> &grid){
        if(i>=n || j>= m) return 1e9; 
        if(dp[i][j] != -1) {  return dp[i][j]; }
        if(i==n-1 && j==m-1) {  return grid[i][j]; }
        int ans = 1e9;
        ans = min(ans,df(i+1,j,n,m,grid)+grid[i][j]);
        ans = min(ans,df(i,j+1,n,m,grid)+grid[i][j]);
        return dp[i][j] = ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        v.resize(grid.size(),vector<int>(grid[0].size(),0));
        return df(0,0,grid.size(),grid[0].size(),grid);
        // return ans;
    }
};
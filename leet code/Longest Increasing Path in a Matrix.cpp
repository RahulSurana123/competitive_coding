

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int dp[200][200];
    int n,m;
    
    int df(int i, int j, vector<vector<int>>& mat,int prev){
        if(i < 0 || j < 0 || i > n-1 || j > m-1 || mat[i][j] <= prev) return 0;
        if(dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 +  max(max(max(df(i+1,j,mat,mat[i][j]),df(i-1,j,mat,mat[i][j])),df(i,j+1,mat,mat[i][j])),df(i,j-1,mat,mat[i][j]));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        n = matrix.size();
        m = matrix[0].size();
        memset(dp,0,sizeof(dp));
        for(int i = 0 ; i  < n ; i++){
            for(int j = 0 ; j  < m ; j++){
                ans = max(ans,df(i,j,matrix,-1));
            }
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
find a water cell such that its distance to the nearest land cell is maximized, and return the distance. 
If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.


    ***********************************************************
*/



#include <bits/stdc++.h>


class Solution {
public:

    vector<vector<int>> dp;

    int maxDistance(vector<vector<int>>& grid) {
        const int n= grid.size();
        dp.resize(n,vector<int>(n,0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] ==1) continue;
                dp[i][j] = 1e3;
                if(i-1>=0){
                    dp[i][j] = min(dp[i][j] , 1+ dp[i-1][j]);
                }
                if(j-1>=0){
                    dp[i][j] = min(dp[i][j] , 1+ dp[i][j-1]);
                }
            }   
        }
        for(int i = n-1; i >=0; i--){
            for(int j = n-1; j >=0; j--){
                if(grid[i][j] ==1) continue;
                if(i+1<n){
                    dp[i][j] = min(dp[i][j] , 1+ dp[i+1][j]);
                }
                if(j+1<n){
                    dp[i][j] = min(dp[i][j] , 1+ dp[i][j+1]);
                }
                ans = max(ans,dp[i][j]);
            }   
        }
        // int ans = bfs1(grid);
        return ans == 0 || ans == 1e3? -1:ans;
    }
};
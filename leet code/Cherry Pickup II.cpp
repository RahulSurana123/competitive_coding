

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),0)));
        dp[0][0][grid[0].size() - 1] = 0 == grid[0].size() - 1 ? grid[0][0] : grid[0][0] + grid[0][grid[0].size() - 1];
        //row traversing
        for (int row = 1; row < grid.size() ; row++) {
            //avoiding unnecessary column computations
            for (int c1 = 0; c1 < min((int)grid[0].size(), row + 1); c1++) {
                for (int c2 = max(0, (int)grid[0].size() - 1 - row); c2 < grid[0].size(); c2++) {
                    int prevMax = 0;
                    //Moves of robos in columns
                    for (int offset1 = max(0, c1 - 1); offset1 <= min((int)grid[0].size() - 1, c1 + 1); offset1++) {
                        for (int offset2 = max(0, c2 - 1); offset2 <= min((int)grid[0].size() - 1, c2 + 1); offset2++) {
                                prevMax = max(prevMax, dp[row - 1][offset1][offset2]); //9 states wediscussed can be summariazed 
                        }
                    }
                    //Robo collision condition
                    if (c1 == c2) dp[row][c1][c2] = prevMax + grid[row][c1];
                    else dp[row][c1][c2] = prevMax + grid[row][c1] + grid[row][c2];
                }
            }
        }
        // df(0,0,grid[0].size()-1,grid);
        int ans = 0;
        for(int i = 0; i < grid[0].size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                ans = max(ans,dp[grid.size()-1][i][j]);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:

    vector<vector<vector<int>>> dp;

    int df(int i, int r1, int r2,vector<vector<int>>& grid){
        if(i >= grid.size()) return 0;
        if(r1 < 0 || r2 > grid[0].size()-1) return -1;
        if(r2 <= r1) return -1e9;
        if(dp[i][r1][r2] != -1) return dp[i][r1][r2];
        int ans = 0;
        ans = max(ans, df(i+1,r1-1,r2-1,grid));
        ans = max(ans, df(i+1,r1-1,r2,grid));
        ans = max(ans, df(i+1,r1-1,r2+1,grid));
        ans = max(ans, df(i+1,r1,r2-1,grid));
        ans = max(ans, df(i+1,r1,r2,grid));
        ans = max(ans, df(i+1,r1,r2+1,grid));
        ans = max(ans, df(i+1,r1+1,r2-1,grid));
        ans = max(ans, df(i+1,r1+1,r2,grid));
        ans = max(ans, df(i+1,r1+1,r2+1,grid));
        return dp[i][r1][r2] = ans + grid[i][r1] + grid[i][r2];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return df(0,0,m-1,grid);
    }
};
*/
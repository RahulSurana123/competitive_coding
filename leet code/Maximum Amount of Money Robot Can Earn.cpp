

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

The grid contains a value coins[i][j] in each cell:

If coins[i][j] >= 0, the robot gains that many coins.
If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

Note: The robot's total coins can be negative.

Return the maximum profit the robot can gain on the route.


    ***********************************************************
*/

class Solution {
public:

    vector<vector<vector<int>>> dp;

    int df(int i, int j, int k, vector<vector<int>>& coins){
        if(i >= coins.size() || j >= coins[0].size() || k<0) return -1e9;
        if(i == coins.size()-1 && j == coins[0].size()-1) {
            if(coins[i][j] < 0) return k > 0? 0: coins[i][j];
            return coins[i][j];
        }
        if(dp[i][j][k] != -1000000) return dp[i][j][k];
        // cout << i <<" "<<j<<" "<<k <<"\n";
        if(coins[i][j] >= 0){
            return dp[i][j][k] = coins[i][j] + max(df(i+1,j,k,coins), df(i,j+1,k,coins));
        }
        else{
            int down = max(df(i+1,j,k,coins)+coins[i][j],df(i+1,j,k-1,coins));
            int right = max(df(i,j+1,k,coins)+coins[i][j],df(i,j+1,k-1,coins));
            return dp[i][j][k] = max(down,right);
        }
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(),m = coins[0].size();
        dp.resize(n+1,vector<vector<int>>(m+1,vector<int>(3,-1000000)));
        return df(0,0,2,coins);
    }
};
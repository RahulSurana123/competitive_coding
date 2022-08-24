

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer n. You have an n x n binary grid grid with all values initially 1's except 
for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] 
where grid[xi][yi] == 0.

Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along 
with four arms of length k - 1 going up, down, left, and right, and made of 1's. 
Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    int dp[501][501][5];
    int v[501][501];
    int dir[5] = {0,1,0,-1,0};
    int df(int i, int j, int d ,vector<vector<bool>> &mines,int n){
        if(i>= n || j >= n || i<0 || j<0  || mines[i][j]) return 0;
        if(dp[i][j][d] != 0) return dp[i][j][d];
        return dp[i][j][d] = df(i+dir[d],j+dir[d+1],d,mines,n)+1;
    }
    
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        memset(dp,0,sizeof(dp));
        int ans = 0;
        vector<vector<bool>> me(n+1,vector<bool>(n+1,false));
        for(auto x: mines){
            me[x[0]][x[1]] = true;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int z = 1e9;
                for(int k = 0; k < 4; k++){
                    z = min(z,df(i,j,k,me,n));
                    // cout << i<<" "<<j<<" "<<k <<" "<<dp[i][j][k] <<"\n";
                }
                ans = max(ans,z);
            }   
        }
        return ans;
    }
};
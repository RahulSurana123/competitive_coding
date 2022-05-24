

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). 
The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any 
square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    vector<vector<int>> v;
    
    int uniquePathsWithObstacles(vector<vector<int>>& oG) {
        v.resize(oG.size()+1, vector<int>(oG[0].size()+1,0));
        v[0][1] = 1;
        for(int i = 1 ; i <= oG.size(); i++){
            for(int j = 1 ; j <= oG[0].size(); j++){
                if(!oG[i-1][j-1]){
                    v[i][j] = v[i-1][j] + v[i][j-1];
                } 
            }   
        }
        return v[oG.size()][oG[0].size()];
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    bool df(int i, int j, vector<vector<int>>& grid){
        for(int k = 0; k  < grid.size(); k++){
            if(grid[i][k] != grid[k][j]) return false;
        }
        return true;
    }

    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                ans += df(i,j,grid);
            }   
        }
        return ans;
    }
};
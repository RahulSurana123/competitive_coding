

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> v(n,vector<bool>(n,false));
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            while(s--){
                pair<int,int> x = q.front();
                q.pop();
                // cout << x.first <<" "<< x.second<<"\n";
                if(x.first == n-1 && x.second == n-1) return ans;
                if(v[x.first][x.second]) continue;
                v[x.first][x.second] = true;
                for(int i = -1; i < 2; i++){
                    for(int j = -1; j < 2; j++){
                        if(i == 0 && j == 0){
                            continue;
                        }
                        else{
                            if(x.first+i < 0 || x.first+i > n-1 || x.second+j <0 || x.second+j >n-1 || grid[x.first+i][x.second+j] || v[x.first+i][x.second+j]) continue;
                            q.push({x.first+i,x.second+j});
                            if(x.first+i == n-1 && x.second+j == n-1) return ans+1;
                         }
                    }   
                }
            }
            ans++;
        }
        return -1;
    }
};
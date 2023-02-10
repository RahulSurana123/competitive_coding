

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

    int bfs1(vector<vector<int>>& grid){
        vector<vector<bool>> v(grid.size(),vector<bool>(grid.size(),false));
        queue<vector<int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid.size(); j++){
                if(grid[i][j])
                q.push({i,j});
            }   
        }
        int step = 0;
        // cout << i <<" "<<j<<" ->\n";
        if(q.size()==grid.size()*grid.size() || q.size()==0) return 0;
        while(!q.empty()){
            int s = q.size();
            step++;
            while(s--){
                auto z = q.front();
                q.pop();
                if(z[0] < 0 || z[1] < 0 || z[0] >= grid.size() || z[1] >= grid[0].size() || v[z[0]][z[1]]) continue;
                v[z[0]][z[1]] = true;
               
                dp[z[0]][z[1]] = step;
           
                // cout << z[0]<<" "<<z[1]<<"\n";
    
                q.push({z[0]+1,z[1]});
                q.push({z[0],z[1]-1});
                q.push({z[0],z[1]+1});
                q.push({z[0]-1,z[1]}); 
            }
        }
        return step-1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid.size(),-1));
        int ans = bfs1(grid);
        return ans == 0? -1:ans-1;
    }
};
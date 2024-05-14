

/* 
    Solution by Rahul Surana
    
    ***********************************************************


In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 
0 if it is empty.

Return the maximum amount of gold you can collect under the conditions:

Every time you are located in a cell you will collect all the gold in that cell.
From your position, you can walk one step to the left, right, up, or down.
You can't visit the same cell more than once.
Never visit a cell with 0 gold.
You can start and stop collecting gold from any position in the grid that has some gold.


    ***********************************************************
*/


class Solution {
public:

    vector<vector<bool>> v;

    int df(int i, int j,vector<vector<int>>& g ){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||v[i][j] || g[i][j] == 0) return 0;
        v[i][j] = true;
        int ans = df(i-1,j,g);
        ans = max(ans,df(i+1,j,g));
        ans = max(ans,df(i,j+1,g));
        ans = max(ans,df(i,j-1,g));
        v[i][j] = false;
        return ans + g[i][j];
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        v.resize(n, vector<bool>(m,false));
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans,df(i,j,grid));
            }
        }
        return ans;
    }
};
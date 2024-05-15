

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:

A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). 
In one move, you can move to any adjacent cell in the grid, including cells containing thieves.

The safeness factor of a path on the grid is defined as the minimum manhattan distance 
from any cell in the path to any thief in the grid.

Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).

An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.

The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, 
where |val| denotes the absolute value of val.


    ***********************************************************
*/


class Solution {
public:

    int n = 0;
    vector<int> dirs = {-1,0,1,0,-1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return 0;
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        queue<vector<int>> q;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){ 
                if(grid[i][j]) { q.push({i,j}); dis[i][j] = 0; } 
            }   
        }
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            for(int i =0; i < 4; i++){
                int newX = x[0] + dirs[i];
                int newY = x[1] + dirs[i+1];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && dis[newX][newY] > 1 + dis[x[0]][x[1]]) { 

                    dis[newX][newY] = 1 + dis[x[0]][x[1]];
                    q.push({newX, newY});
                }
            }
        }
        priority_queue<vector<int>> pq;
        pq.push({dis[0][0],0,0});
        while(!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            if(x[1] == n-1 && x[2] == n-1) return x[0];
            vis[x[1]][x[2]] = true;
            for(int i =0; i < 4; i++){
                int newX = x[1] + dirs[i];
                int newY = x[2] + dirs[i+1];

                if(newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]) { 
                    int s = min(x[0], dis[newX][newY]);
                    pq.push({s,newX, newY});
                    vis[newX][newY] = true;
                }
            }

        }
        return -1;
    }
};
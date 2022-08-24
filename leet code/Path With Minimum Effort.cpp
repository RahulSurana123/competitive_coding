

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), 
and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
     
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};

        std::vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, 0); // First item is effort, second is row * 100 + col
        while (!pq.empty()) {
          int effort = pq.top().first;
          int x = pq.top().second / 100, y = pq.top().second % 100;
          pq.pop();

          if (x == m - 1 && y == n - 1) return effort;
          if (effort >= efforts[x][y]) continue;
          efforts[x][y] = effort;

          for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
            pq.emplace(n_effort, nx * 100 + ny);
          }
        }
        return -1;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.


    ***********************************************************
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int diff = 0, n = grid.size(), m = grid[0].size();
        vector<int> v;
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m; j++){
                v.push_back(grid[i][j]);
                if(abs(grid[0][0] - grid[i][j]) %x != 0) return -1;
            }
        }
        sort(v.begin(),v.end());
        int va = v[v.size()/2], ans = 0;
        for(int j = 0;j < v.size(); j++){
            ans += abs(va - v[j])/x;
        }
        return ans;
    }
};



/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.


    ***********************************************************
*/


class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& g) {
        vector<vector<int>> o(g.size()-2,vector<int>(g[0].size()-2,0));
        for(int i = 0; i < o.size();i++){
            for(int j = 0; j < o[i].size();j++){
                o[i][j] = max(g[i][j+2],max(g[i+1][j+2],max(g[i+2][j+2],max(g[i+2][j+1],max(g[i+2][j],max(g[i+1][j+1],max(g[i][j+1],max(g[i][j],g[i+1][j]))))))));
            }   
        }
        return o;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed m x n binary matrix grid.

A 0-indexed m x n difference matrix diff is created with the following procedure:

Let the number of ones in the ith row be onesRowi.
Let the number of ones in the jth column be onesColj.
Let the number of zeros in the ith row be zerosRowi.
Let the number of zeros in the jth column be zerosColj.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
Return the difference matrix diff.


    ***********************************************************
*/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        vector<int> r(n,0),c(m,0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                bool x = (grid[i][j]==0);
                r[i] += x;
                c[j] += x;
            }
        }
        vector<vector<int>> d(n,vector<int>(m,m+n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                d[i][j] -= 2*(r[i]+c[j]);
            }
        }
        return d;
    }
};
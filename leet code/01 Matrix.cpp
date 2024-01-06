

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



    ***********************************************************
*/

class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> v(m,vector<bool>(n,false));
        int step = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto a = q.front();
                auto x = a[0], y = a[1];
                q.pop();
                if(x < 0 || x > m-1 || y < 0 || y > n-1 || v[x][y]) continue;
                if(mat[x][y] != 0)
                mat[x][y] = step;
                v[x][y] = true;
                q.push({x+1,y});
                q.push({x,y+1});
                q.push({x-1,y});
                q.push({x,y-1});
            }
            step++;
        }
        return mat;
    }
};
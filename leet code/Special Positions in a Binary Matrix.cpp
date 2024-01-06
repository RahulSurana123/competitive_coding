

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an m x n binary matrix mat, return the number of special positions in mat.

A position (i, j) is called special if mat[i][j] == 1 and 
all other elements in row i and column j are 0 (rows and columns are 0-indexed).


    ***********************************************************
*/

    
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int idx = -1;
            for(int j = 0; j < m; j++){
                if(idx == -1 && mat[i][j] == 1) idx = j;
                else if(idx != -1 && mat[i][j]) {idx = -1; break;}
            } 
            if(idx == -1) continue;
            bool f = true;
            for(int k = 0; k < n; k++){
                if(mat[k][idx] == 1 && k != i) { f = false; break;}
            }
            if(f) ans++;
        }
        return ans;
    }
};
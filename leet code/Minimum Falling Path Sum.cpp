

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that 
is either directly below or diagonally left/right. 
Specifically, the next element from position (row, col) will be 
(row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = 1e9;
        // vector<int> dp(n,0);
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int a = matrix[i+1][j];
                if(j != 0)
                a = min(a, matrix[i+1][j-1]);
                if(j != n-1)
                a = min(a, matrix[i+1][j+1]);
                matrix[i][j] += a;
                // cout << j <<" "<<dp[j] <<"\n";
            }
            // for(auto &x : dp) cout << x<<" ";
            // cout <<"\n";
        }
        for(int i = n-1; i >= 0; i--) { ans = min(ans, matrix[0][i]); } 
        return ans;
    }
};
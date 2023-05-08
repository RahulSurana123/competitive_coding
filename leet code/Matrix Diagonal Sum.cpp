

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and 
all the elements on the secondary diagonal that are not part of the primary diagonal.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };

    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0, n = mat.size(); 
        for(int i = 0 ; i < mat.size(); i++){
            sum += mat[i][i] + mat[i][n-1-i];
            if(i==n-1-i) sum -= mat[i][i];
        } 
        return sum;
    }
};
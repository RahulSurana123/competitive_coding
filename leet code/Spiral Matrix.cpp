

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given an m x n matrix, return all elements of the matrix in spiral order.

 

    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int c = matrix.size()*matrix[0].size(), i = 0, j = 0, il = 0,jl = 0;
        vector<int> ans;
        while(ans.size() < c){
            while(j < matrix[0].size()-jl) ans.push_back(matrix[i][j++]);
            i++;
            j--;
            if(ans.size() == c) break;
            while(i < matrix.size()-il) ans.push_back(matrix[i++][j]);
            j--;
            i--;
            if(ans.size() == c) break;
            while(j >= jl) ans.push_back(matrix[i][j--]);
            i--;
            j++;
            if(ans.size() == c) break;
            while(i > il) ans.push_back(matrix[i--][j]);
            j++;
            il++;
            jl++;
            i = il;
        }
        return ans;
    }
};
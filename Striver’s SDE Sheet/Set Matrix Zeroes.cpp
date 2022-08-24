

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an m x n integer matrix matrix, 
if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 


    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows;
        set<int> cols;
        for(int i = 0 ; i < matrix.size() ;i++){
            for(int j = 0 ; j < matrix[i].size() ;j++){
                if(matrix[i][j] == 0) {rows.insert(i); cols.insert(j);}
            }   
        }
        for(int i = 0 ; i < matrix.size() ;i++){
            for(int j = 0 ; j < matrix[i].size() ;j++){
                if(rows.count(i) || cols.count(j)) {matrix[i][j] = 0;}
            }   
        }
    }
};
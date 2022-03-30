

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0,j=0;
        while(i<matrix.size() && matrix[i][matrix[i].size()-1] < target) i++;
        if(i==matrix.size()) return false;
        while(j < matrix[0].size() && matrix[i][j] < target) j++;
        if(j == matrix[0].size()) return false;
        return matrix[i][j] == target;
    }
};
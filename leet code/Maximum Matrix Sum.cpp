


/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.


    ***********************************************************
*/



class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count = 0;
        int min = 100001;
        long long sum = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0) count++;
                if(min > abs(matrix[i][j])) min = abs(matrix[i][j]);
            }
        }
        if(count %2) sum -= (2*min);
        return sum;
    }
};
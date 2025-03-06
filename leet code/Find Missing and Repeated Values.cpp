
/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
Each integer appears exactly once except a which appears twice and b which is missing. 
The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.



    ***********************************************************
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long a = 0; // sum n*(n+1)/2 - difference between both value
        long long b = 0; // sum n(n+1)(2n+1)/6 - missing and repeating
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int v = i*n +j+1;
                a-=v;
                a+=grid[i][j];
                b-=(v*v);
                b+=(grid[i][j]*grid[i][j]);
            }
        }
        int c = b/a; // miss + rep
        int miss = (c - a)/2, rep = (c+a)/2;
        return {rep,miss};
    }
};

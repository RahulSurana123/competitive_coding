

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
return the number of negative numbers in grid.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(auto &r: grid){
            ans += upper_bound(r.rbegin(),r.rend(),-1) - r.rbegin();
        }
        return ans;
    }
};
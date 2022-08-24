

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 



    ***********************************************************
*/


#include<bits/stdc++.h>

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1 ; i < triangle.size(); i++){
            for(int j = 0 ; j < triangle[i].size(); j++){
                // if(i = 0 && j == 0)triangle[i][j]
                if(j == triangle[i].size()-1){
                    triangle[i][j] += triangle[i-1][j-1];
                }
                else if(j == 0) triangle[i][j] += triangle[i-1][j]; 
                else triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
            }
        }
        int ans = 1e9;
        for(auto x: triangle[triangle.size()-1]){
            // cout << x <<" ";
            ans = min(x,ans);
        }
        return ans;
    }
};
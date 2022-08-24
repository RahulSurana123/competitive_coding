

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
         vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 0; i < strs.size(); i++){
            int z = 0,o = 0;
            for(int j = 0; j < strs[i].size(); j++){
                if(strs[i][j] == '0') z++;
                else o++;
            }   
            for(int j = m; j >= z; j--){
                for(int k = n; k >= o; k--){
                    dp[j][k] = max(dp[j][k], dp[j-z][k-o]+1);
                }   
            }
        }    
        return dp[m][n];    
    }
};
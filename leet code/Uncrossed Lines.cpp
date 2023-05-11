

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given two integer arrays nums1 and nums2. 
We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:

nums1[i] == nums2[j], and
the line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).

Return the maximum number of connecting lines we can draw in this way.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:


    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+1, m = nums2.size()+1;
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                // cout << dp[i][j]<<" ";
            }
            // cout <<"\n";
        }
        return dp[n-1][m-1];
    }
};


/* 

    Solution by Rahul Surana

    ***********************************************************

Given an integer n, return the number of structurally unique BST's 
(binary search trees) which has exactly n nodes of unique values from 1 to n.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    vector<int> dp;
    
    int dpx(int n){
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        dp[n] = 0;
        for(int i = n-1; i>=0; i--){
            dp[n] += (dpx(i) * dpx(n-1-i));
        }
        cout << dp[n]<<" ";
        return dp[n];
    }
    
    int numTrees(int n) {
        dp.resize(n+1,-1);
        return dpx(n);
    }
};


/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by 
deleting some or no elements without changing the order of the remaining elements.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int df(int i, int j, string &s,vector<vector<int>> &dp){
        if(dp[i][j] != -1) return dp[i][j];
        if(i>j) return 0;
        if(i==j) return 1;
        if(s[i] == s[j]){
            return dp[i][j] = (2) + df(i+1,j-1,s,dp);
        }
        return dp[i][j] = max(df(i,j-1,s,dp),df(i+1,j,s,dp));
    }

    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return df(0,s.length()-1,s,dp);
    }
};
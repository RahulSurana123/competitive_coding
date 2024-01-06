

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given an integer array arr and an integer difference, 
return the length of the longest subsequence in arr which is an arithmetic sequence such that 
the difference between adjacent elements in the subsequence equals difference.

A subsequence is a sequence that can be derived from arr by deleting some or no elements without 
changing the order of the remaining elements.


    ***********************************************************
*/


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 0;
        for(auto &a: arr){
            dp[a]= dp[a-difference]+1;
            ans = max(ans,dp[a]);
        }
        return ans;
    }
};
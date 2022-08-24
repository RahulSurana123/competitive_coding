

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a non-empty array nums containing only positive integers, 
find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    vector<vector<int>> dp;
    
    bool df(int i, int n,vector<int>& nums, int s, int d){
        if(i>=n || s>d) return false;
        if(s==d) return dp[i][s] = true;
        if(dp[i][s] != -1) return dp[i][s];
        bool x = false;
        x = df(i+1,n,nums,s+nums[i],d);
        if(x) return dp[i][s] = true;
        else return dp[i][s] = df(i+1,n,nums,s,d);
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i = 0 ; i < n; i++){
            s+=nums[i];
        }
        if(s&1) return false;
        else { 
            dp.resize(n,vector<int>((s/2)+1,-1));
            return df(0,n,nums,0,s/2);
        }
    }
};
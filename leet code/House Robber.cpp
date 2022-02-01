

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that 
adjacent houses have security systems connected and it will automatically contact the police 
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {

public:
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        if(nums.size()==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};
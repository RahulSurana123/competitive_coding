

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
    
    vector<int> dp;
    
    int ls(vector<int>& nums, int i){
        if(i > nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        int m = nums[i];
        for(int j = i+2; j < nums.size(); j++){
            m = max(m,ls(nums,j)+nums[i]);
        }
        cout << m <<" " << i <<"\n";
        return dp[i]=m;
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return max(ls(nums,0),ls(nums,1));
    }
};
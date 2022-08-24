

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
        if(nums.size()==1) return nums[0];
        int a = nums[0], b = max(nums[0],nums[1]); 
        for(int i = 2; i < nums.size(); i++){
            int c = max(nums[i]+a,b);
            a = b;
            b = c;
        }
        return b;
    }
};
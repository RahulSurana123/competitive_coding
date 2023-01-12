

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 
All houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    
    int df(int s, int e, vector<int>& nums){
        int a = nums[s], b = max(nums[s],((s+1)<nums.size())?nums[s+1]:0);
        for(int i = s+2; i <= e; i++){
            int c = max(a+nums[i],b);
            a = b;
            b = c;
        }
        return b;
    }
    
    int rob(vector<int>& nums) {
       if(nums.size()==1) return nums[0];
        return max(df(0,nums.size()-2,nums),df(1,nums.size()-1,nums));
    }
};
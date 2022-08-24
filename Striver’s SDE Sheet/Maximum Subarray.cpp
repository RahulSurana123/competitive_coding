

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

 

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs = nums[0], ms = nums[0];
        for(int i = 1; i < nums.size(); i++){
            cs += nums[i];
            cs = max(cs,nums[i]);
            ms = max(ms,cs);
        }
        return ms;
    }
};
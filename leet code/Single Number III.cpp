

/* 

    Solution by Rahul Surana

    ***********************************************************

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2) return nums;
        int e = 0,m = 1e9;
        bool u = false;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i+=2) { 
            e ^= nums[i];
            e ^= nums[i-1];
            if(nums[i] != nums[i-1]){ 
                if(!u) { 
                    m = nums[i-1]; 
                    u = true;
                }
            } 
        }
        return {m,e^m};
    }
};
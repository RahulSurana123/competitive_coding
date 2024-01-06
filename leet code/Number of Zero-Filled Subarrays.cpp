

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, return the number of subarrays filled with 0.

A subarray is a contiguous non-empty sequence of elements within an array.



    ***********************************************************
*/



#include<bits/stdc++.h>

class Solution {
public:

    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0; 
        while(i<nums.size()){
            while(i < nums.size() && nums[i]!=0) i++;
            int a = 0;
            while(i < nums.size() && nums[i++]==0) { a++; ans+=a; }
        }
        return ans;
    }
};
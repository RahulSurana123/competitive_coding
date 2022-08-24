

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, 
and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans = INT_MIN;
        int i = 0,j = 0;
        for(auto n: nums){
            if(n < 0) swap(i,j);
            i = max(i*n,n);
            j = min(j*n,n);
            ans = max(ans,i);
        }
        return ans;
    }
};
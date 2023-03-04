

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.


    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int i = -1, j = -1, k = -1;
        for(int x = 0; x < nums.size(); x++){
            if(nums[x] == minK){
                i = x;
            }
            if(nums[x] == maxK){
                j=x;
            }
            if(nums[x] > maxK || nums[x] < minK){
                k = x;
            }
            ans += max(0,min(i,j)-k);
        }
        return ans;
    }
};
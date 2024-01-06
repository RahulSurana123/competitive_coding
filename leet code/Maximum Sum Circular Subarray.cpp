



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. 
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. 
Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = INT_MIN, minSum = INT_MAX;
        int currMax = 0, currMin = 0;
        int totalSum = 0;
        for(auto i : nums) {
            currMax = max(i,currMax + i);
            maxSum = max(maxSum, currMax);
            currMin = min(i, currMin + i);
            minSum = min(minSum, currMin);
            totalSum += i;
        }
        return maxSum > 0? max(maxSum, totalSum - minSum) : maxSum;
    }
};
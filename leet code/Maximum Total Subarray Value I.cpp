

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given an integer array nums of length n and an integer k.

You need to choose exactly k non-empty subarrays nums[l..r] of nums. Subarrays may overlap, and the exact same subarray (same l and r) can be chosen more than once.

The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value you can achieve.


    ***********************************************************
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int ma = 0;
        int mi = 1e9;
        for(auto x: nums) {
            ma = max(ma,x);
            mi = min(mi,x);
        }
        return 1LL*(ma-mi)*k;
    }
};

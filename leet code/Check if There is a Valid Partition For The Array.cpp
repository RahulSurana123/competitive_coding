

/* 

    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. 
For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.



    ***********************************************************
*/


class Solution {
public:
vector<int > dp;

    bool df(int i, vector<int>& nums){
        if(i > nums.size()-1) return true;
        if(dp[i] != -1) return dp[i];
        if(i+1 < nums.size() && nums[i] == nums[i+1]) {
            if(df(i+2,nums)) return dp[i] = true;
            if(i+2 < nums.size() && nums[i+2] == nums[i+1] && df(i+3,nums)) return dp[i] = true;
            else dp[i] = false;
        }
        if(i+3 <= nums.size() && (nums[i]+1 == nums[i+1] && nums[i+2] == nums[i+1]+1) && df(i+3,nums)) return dp[i] = true; 
        return dp[i] = false;
    }

    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return df(0, nums);
    }
};
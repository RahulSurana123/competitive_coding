


/* 
    Solution by Rahul Surana
    
    ***********************************************************

The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.

    ***********************************************************
*/



class Solution {
public:
    
    int MOD = 1000000007;
    
    int maxSumMinProduct(vector<int>& nums) {
        long ans=0;
        vector<long> pre(nums.size()+1,0),s;
        for(int i = 0; i < nums.size(); i++){
            pre[i+1] = nums[i] +pre[i];
        }
        for(int i = 0; i <= nums.size(); ++i){
            while(!s.empty() && (i==nums.size() || nums[s.back()] > nums[i])){
                auto x = s.back();
                s.pop_back();
                ans = max(ans,(nums[x]*(pre[i] - pre[s.empty() ? 0 : s.back()+1])));
            }
            s.push_back(i);
        }
        return ans%MOD;
    }
};
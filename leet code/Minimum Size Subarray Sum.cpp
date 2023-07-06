

/* 

    Solution by Rahul Surana
    
    ***********************************************************

Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


    ***********************************************************
*/


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, s = 0,ans = 1e9;
        while(j<nums.size()){
            while(j < nums.size() && s < target) s+=nums[j++];
            if(s >= target)
            ans = min(ans,j-i+1);
            while(i<nums.size() && s >= target) s-=nums[i++];
            if(s < target)
            ans = min(ans,j-i+1);
        }   
        return ans>nums.size()? 0:ans;
    }
};
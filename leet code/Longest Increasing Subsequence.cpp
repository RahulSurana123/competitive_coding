

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an integer array nums, return the length of the longest strictly increasing subsequence.


    ***********************************************************
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(1,nums[0]);
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(lis.back()<nums[i]) lis.push_back(nums[i]);
            else{
                auto z = lower_bound(lis.begin(),lis.end(),nums[i]);
                *z = nums[i];
            }
        }
        return lis.size();
    }
};
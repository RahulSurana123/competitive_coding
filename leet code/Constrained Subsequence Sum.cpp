

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums and an integer k, 
return the maximum sum of a non-empty subsequence of that array such that for every two 
consecutive integers in the subsequence, nums[i] and nums[j], 
where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, 
leaving the remaining elements in their original order.


    ***********************************************************
    
*/

class Solution {
public:

    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> ans;
        for(int i = 0; i < nums.size(); i++){
            nums[i] += !ans.empty()?nums[ans.front()]:0;
            while(!ans.empty() && ( i - ans.front() >= k || nums[i] >= nums[ans.back()])){
                if(nums[i] >= nums[ans.back()]) ans.pop_back();
                else ans.pop_front();
            }
            if(nums[i] > 0) ans.push_back(i);
        }

        int val = -1e9;
        for(auto x: nums) val = max(val,x);
        return val;
    }
};
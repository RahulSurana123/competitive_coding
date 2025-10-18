


/* 

    Solution by Rahul Surana
    

    ***********************************************************


You are given an integer array nums and an integer k.

You are allowed to perform the following operation on each element of the array at most once:

Add an integer in the range [-k, k] to the element.
Return the maximum possible number of distinct elements in nums after performing the operations.

        

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0, prev = -1e9;
        for(int i = 0; i < nums.size(); i++){
           int l = max(nums[i] - k, prev + 1);
            if (l <= nums[i] + k) {
                prev = l, ans++;
            }
        }
        return ans;
    }
};

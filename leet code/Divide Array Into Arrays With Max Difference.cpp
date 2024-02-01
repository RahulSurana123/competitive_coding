

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums of size n and a positive integer k.

Divide the array into one or more arrays of size 3 satisfying the following conditions:

Each element of nums should be in exactly one array.
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing all the arrays. If it is impossible to satisfy the conditions, 
return an empty array. And if there are multiple answers, return any of them.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {     
        int n = nums.size();
        vector<vector<int>> ans(n/3);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i+=3){
            if(nums[i+2] - nums[i] > k) return {};
            ans[i/3] = { nums[i], nums[i+1], nums[i+2] };
        }
        return ans;
    }
};
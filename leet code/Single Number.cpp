

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto x: nums){
            ans = ans^x;
        }
        return ans;
    }
};
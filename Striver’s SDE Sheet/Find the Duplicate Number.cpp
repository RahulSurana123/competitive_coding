


/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[nums[0]];
        while(s!=f){
            s = nums[s];
            f = nums[nums[f]];
        }
        f = 0;
        while(f!=s){
            f = nums[f];
            s = nums[s];
        }
        return s;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int extra = -1;
        sort(nums.begin(),nums.end());
        int x = nums[0], n = nums.size();
        for(int i = 1; i < n; i++){ if(nums[i] == nums[i-1]) extra = nums[i]; x+=nums[i]; }
        return {extra , (n*(n+1)/2)-(x-extra) };
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, move all the even integers at the beginning of the array 
followed by all the odd integers.

Return any array that satisfies this condition.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0) { swap(nums[i],nums[j]); j++; }

        }   
        return nums;
    }
};
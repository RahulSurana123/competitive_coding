

/* 
    Solution by Rahul Surana
    
    ***********************************************************


An integer array is called arithmetic if it consists of at least three elements and 
if the difference between any two consecutive elements is the same.

For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
Given an integer array nums, return the number of arithmetic subarrays of nums.

A subarray is a contiguous subsequence of the array.



    ***********************************************************
*/


#include<bits/stdc++.h>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int d = nums[1]-nums[0];
        int i = 0, j = 0;
        int ans = 0;
        while(j < nums.size()){
            while(j<nums.size()-1 && j-i+1<3)j++;
            if(j-i+1 == 3){
                if(nums[j-1] - nums[j-2] == nums[j] - nums[j-1]){
                    d = nums[j-1] - nums[j-2];
                    j++;
                }
                else{
                    i++;
                    j++;
                }
            }
            else if(j-i+1 > 3){
                if(nums[j]-nums[j-1]==d)j++;
                else{
                    int c = j - i +1 -3;
                    ans += ((c*(c+1))/2);
                    i = j-1;
                }
            }
            
        }
        if(j-i+1 > 3) { 
            int c = j - i +1 -3;
            ans += ((c*(c+1))/2);
        }
        return ans;
    }
};
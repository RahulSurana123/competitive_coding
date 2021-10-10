

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 1,i = 0;
        while(j < n && i < n){
            if(j > i && nums[i] == 0 && nums[j]!=0){
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
            if(i<n && nums[i] != 0){
                i++;
            }
            if((j < n && nums[j] == 0) || i >= j) j++;
            // cout << i << " " << j << "\n";
        }
    }
};
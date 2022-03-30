

/* 

    Solution by Rahul Surana
    
    ***********************************************************


There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1) return target == nums[0];
        int z = nums.size()-1;
        for(int i = 0; i < nums.size()-1; i++) if(nums[i] > nums[i+1]) z = i;
        int s = 0,e = nums.size() - 1;
        while(s<=e){
            int m = s + (e-s)/2;
            if(nums[m] == target) return true;
            if(nums[s] == nums[m] && nums[m] == nums[e]){
                s++;
                e--;
            }
            else if(nums[s] <= nums[m]){
                if(nums[m] > target && target >= nums[s]) { e = m-1; }
                else{
                    s = m+1;
                }
            } 
            else {
                if(nums[e] >= target && nums[m] < target) s = m+1;
                else {
                    e = m-1;
                }  
            } 
            cout << m << " ";
        }
        return false;
    }
};
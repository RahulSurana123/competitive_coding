

/* 
    Solution by Rahul Surana
    
    ***********************************************************


There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    int findk(vector<int>&nums, int i, int j){
        if(i > j){
            return -1;
        }
        if(i == j) return i;
        int m = (i+j)/2;
        if(m < j && nums[m] > nums[m+1]) return m;
        if(m > i && nums[m] < nums[m-1]) return m-1;
        if(nums[i]>=nums[m]) return findk(nums,i,m-1);
        return findk(nums,m+1,j); 
    }

    int search(vector<int>& nums, int target) {
        int j = nums.size();
        if(j == 1) return nums[0] == target? 0:-1;
        int k = findk(nums,0,j-1)+1;
        for(int i = 0; i < j; i++) nums.push_back(nums[i]);
        // cout << k <<" "<< j<<"\n";
        int s = k, e = j+k;
        while(s<=e){
            int m = (s+e)/2;
            if(nums[m] == target) return m%j;
            else if(nums[m] < target){
                s = m+1;
            }
            else{
                e = m-1;
            }
            // cout <<nums[m]<<" " <<m  <<" "<<s <<" "<<e <<"\n";
        }
        return -1;
    }
};
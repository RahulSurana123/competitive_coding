

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums, you need to find one continuous subarray that 
if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int j = -1, k = -1, ma = INT_MIN;
        for(int i = 0 ; i < nums.size(); i++){
            if(ma>nums[i]){
                if(j == -1) { j = i-1; }
                while(j-1 >= 0 && nums[j-1] > nums[i]) j--;        
                k = i+1;
            }
            else{
                ma = max(ma,nums[i]);
            }
        }
        // cout << j << " "<<k<<" "<< k-j+1<<"\n";
        return k-j;
    }
};
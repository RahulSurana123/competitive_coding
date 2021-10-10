

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once.
The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, 
you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. 
It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        int i = 1, j = 0;
        
        while(j < nums.size()){
            int k = 1;
            
            while(j+k < nums.size() && nums[j+k] == nums[j]) k++;
            if(j+k < nums.size()) nums[i++] = nums[j+k];
            j = j+k;
        }
        
        return i;
    }
};
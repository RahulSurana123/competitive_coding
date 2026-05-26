

/* 
    Solution by Rahul Surana
    
    ***********************************************************

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.


    ***********************************************************
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0;
        for(int i = 0; i < nums.size()-1; i++){
            
            if(nums[i] > nums[i+1]) { c++; }
        }
        if(nums[0] < nums.back()) c++;
        return c<=1;
    }
};

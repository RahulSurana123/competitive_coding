

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

All the integers in nums appear only once except for precisely one integer which appears two or more times.


    ***********************************************************
    
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int f = 0, s = 0;
        while(true){
            f = nums[nums[f]];
            s = nums[s];
            if(f==s) break;
        }
        f = 0;
        while(true){
            f = nums[f];
            s = nums[s];
            if(f==s) return s;
        }
        return -1;
    }
};
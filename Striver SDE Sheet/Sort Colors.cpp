

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int m = 0;
        while(m<=h){
            if(nums[m] == 0){
                nums[m++] = nums[l];
                nums[l++] = 0;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                nums[m] = nums[h];
                nums[h]=2;
                h--;
            }
        }
    }
}; 
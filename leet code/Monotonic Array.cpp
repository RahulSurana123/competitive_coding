

/* 
    Solution by Rahul Surana
    
    ***********************************************************


An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. 
An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 


    ***********************************************************
*/


class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()<=2) return true;
        int  x = nums[0];
        int gI = 0;
        for(int i = 1;i < nums.size(); i++){
            if(x == nums[i]){
                continue;
            }else if(( gI == -1 && x<nums[i])||(gI == 1 && x > nums[i])){
                return false;
            }else if(x < nums[i])
            {
                gI = 1;
            }else {
                gI = -1;
            }
            x = nums[i];
        }
        return true;
    }
};
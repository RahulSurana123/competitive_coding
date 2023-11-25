

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums sorted in non-decreasing order.

Build and return an integer array result with the same length as nums such that 
result[i] is equal to the summation of absolute differences 
between nums[i] and all the other elements in the array.

In other words, result[i] is equal to sum(|nums[i]-nums[j]|) 
where 0 <= j < nums.length and j != i (0-indexed).


    ***********************************************************
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int s = 0 , n = nums.size();
        for(int i = 0; i < n; i++) s+=nums[i];
        int p = 0, pp = nums[0];
        for(int i = 0; i < n; i++){
            p += (nums[i] - pp)*i;
            pp = nums[i];
            s -= nums[i]; 
            nums[i] = s + p - (nums[i]*(n-i-1));
        }
        return nums;
    }
};
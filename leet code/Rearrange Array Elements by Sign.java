

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should rearrange the elements of nums such that the modified array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.



    ***********************************************************
*/

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int j = 1, i = 0;
        int[] ans = new int[nums.length];
        for(int x: nums){
            if(x < 0) {
                ans[j] = x; 
                j += 2;
            }
            else{
                ans[i] = x;
                i += 2;
            }
        }
        return ans;
    }
}


/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an integer array nums of length n.

Assume arrk to be an array obtained by rotating nums by k positions clock-wise. 
We define the rotation function F on nums as follow:

F(k) = 0 * arrk[0] + 1 * arrk[1] + ... + (n - 1) * arrk[n - 1].
Return the maximum value of F(0), F(1), ..., F(n-1).

The test cases are generated so that the answer fits in a 32-bit integer.


    ***********************************************************
*/


class Solution {
    public int maxRotateFunction(int[] nums) {
        int s = 0;
        int fval = 0;
        for(int i = 0; i < nums.length; i++){
            s+=nums[i];
            fval += (i*nums[i]);
        }
        int ans = fval;
        for(int i = 0; i < nums.length; i++){
            fval += (s - (nums.length * nums[nums.length-1-i]));
            // System.out.println(i + " " + fval);
            ans = Math.max(ans,fval); 
        }
        return ans;
    }
}
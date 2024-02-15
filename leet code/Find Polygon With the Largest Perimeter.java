

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of positive integers nums of length n.

A polygon is a closed plane figure that has at least 3 sides. 
The longest side of a polygon is smaller than the sum of its other sides.

Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak 
where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, 
then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.

The perimeter of a polygon is the sum of lengths of its sides.

Return the largest possible perimeter of a polygon whose sides can be formed from nums, 
or -1 if it is not possible to create a polygon.


    ***********************************************************
*/

class Solution {

    long ans = 0;
   
    public long largestPerimeter(int[] nums) {
        Arrays.sort(nums);
        long s = nums[0] + nums[1];
        for(int i = 2; i < nums.length; i++){
            s+=nums[i];
            if(2*nums[i] < s) ans = s;
        }
        return ans==0?-1:ans;
    }
}
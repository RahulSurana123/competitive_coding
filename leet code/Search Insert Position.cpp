/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
 


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0,e = nums.size()-1,m;
        while(s<e){
            m = (s + e)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) e = m-1;
            else { s = m+1; }
        }
        if(nums[s] >= target) return s;
        else return s+1;
    }
};
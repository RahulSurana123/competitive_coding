

/* 

    Solution by Rahul Surana

    ***********************************************************

Given an array of integers nums, you start with an initial positive value startValue.

In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).

Return the minimum positive value of startValue such that the step by step sum is never less than 1.



    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = INT_MAX;
        int s = 0;
        for(auto x: nums){
            s+=x;
            if(s<min){
                min = s;
            }
        }
        if(min >=0) return 1;
        return -min+1;
    }
};
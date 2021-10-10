


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array, rotate the array to the right by k steps, where k is non-negative.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        // for()
        std::rotate(nums.begin(),nums.begin()+nums.size()-k,nums.end());
    }
};


/* 

    Solution by Rahul Surana

    ***********************************************************

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> x;
        for(auto z: nums){
            if(x.count(z)) x.erase(z);
            else x.insert(z);
        }
        return vector<int>(x.begin(),x.end());
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    
    set<vector<int>> ans;
    
    void df(int i, vector<int>& nums,vector<int> r){
        if(i>=nums.size()) return;
        df(i+1,nums,r);
        ans.insert(r);
        r.push_back(nums[i]);
        df(i+1,nums,r);
        ans.insert(r);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        df(0,nums,vector<int>());
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};
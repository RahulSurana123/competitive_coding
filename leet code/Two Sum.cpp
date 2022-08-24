

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,pair<int,int>> m;
        vector<int> ans;
        int i = 0;
        for(auto x: nums){
            if(m[target-x].first != 0){
                ans.push_back(m[target-x].second);
                ans.push_back(i);
                return ans;
            }
            else{
                m[x] = make_pair(1,i); 
            }
            // cout << x <<" "<< m[x].second <<"\n";
            i++;
        }
        return vector<int>();
    }
};
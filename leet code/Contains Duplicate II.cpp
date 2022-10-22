

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums and an integer k, return true 
if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    unordered_map<int,vector<uint8_t>> um;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        uint8_t  size = nums.size() - 1;
        for(uint8_t i =0; i <= size; i++){
            um[nums[i]].push_back(i);
        }
        for(auto x : um){
            for(uint8_t i =1; i < x.second.size(); i++){
                if((x.second)[i] - (x.second)[i-1] <= k) return true;
            }
        }
        return false;
    }
};
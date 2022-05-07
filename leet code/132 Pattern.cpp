

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] 
such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.



    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int mi = INT_MIN;
        stack<int> s;
        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i] < mi) return true;
            else{
                while(!s.empty() && s.top() < nums[i]){
                    mi = s.top();
                    s.pop();
                }
            }
            // if(s.empty() || s.top() > nums[i]) 
            s.push(nums[i]);
        }
        return false;
    }
};
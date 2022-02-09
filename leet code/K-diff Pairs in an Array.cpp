

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i < j < nums.length
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.size()<=1) return 0;
        sort(nums.begin(),nums.end());
        set<int> s;
        int i = 0, j = 1;
        while(i < nums.size() && j < nums.size()){
            if(nums[j] - nums[i] == k){
                s.insert(nums[i]);
                i++;
                j++;
                if(j < nums.size() && nums[j] == nums[j-1]) j++;
            }
            else if(nums[j] - nums[i] > k){
                i++;
                if(i==j) j++;
            }
            else{
                j++;
            }
            
        }
        return s.size();
    }
};
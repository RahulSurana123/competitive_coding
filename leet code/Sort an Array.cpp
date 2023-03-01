

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) 
time complexity and with the smallest space complexity possible.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:

    int solve(vector<int>& nums, int s, int e){
        if(s==e) return s;
        int m = (s+e)/2;
        swap(nums[m],nums[e]);
        int i = s;
        for(int j = s; j < e;j++){
            if(nums[j] <= nums[e]) {
                swap(nums[i],nums[j]);
                i++;
            }
        }
        swap(nums[i],nums[e]);
        return i;
    }

    void quicksort(vector<int>& nums, int s, int e){
        if(s<e) {
            int m = solve(nums,s,e);
            quicksort(nums,s,m-1);
            quicksort(nums,m+1,e);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end())) return nums;
        quicksort(nums,0,nums.size()-1);
        return nums;
    }
};
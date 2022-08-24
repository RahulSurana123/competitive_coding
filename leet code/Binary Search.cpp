

/* 

    Solution by Rahul Surana
    

    ***********************************************************


Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

 



    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    
    int binarySearch(vector<int> nums, int s, int e,int t){
        int mid = s + (e-s)/2;
        if(e<s) return -1;
        cout << nums[mid]<<" ";
        if(nums[mid] == t) return mid;
        else if(nums[mid]>t) return binarySearch(nums,s,mid-1,t);
        else return binarySearch(nums,mid+1,e,t);
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};
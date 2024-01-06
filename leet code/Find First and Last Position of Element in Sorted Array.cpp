

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers nums sorted in non-decreasing order, .
find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


    ***********************************************************
*/


class Solution {
public:

    int bs(int s, int e, int &t, vector<int>& nums, bool isS){
        if(s>e) return -1;
        if(s == e){
            if(nums[s] == t) return s;
            return -1;
        }
        int m = s+(e-s)/2;
        int sm = bs(s,m,t,nums,isS);
        int me = bs(m+1,e,t,nums, isS);
        if(sm == -1 && me == -1) return -1;
        if(sm == -1) return me;
        if(me == -1) return sm;
        return isS? sm:me;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
       int n = nums.size()-1;
       int s = bs(0,n,target,nums,true);
       int e = bs(0,n,target,nums,false);
       return {s,e};
    }
};
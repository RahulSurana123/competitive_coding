

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array nums which consists of non-negative integers and an integer m, 
you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0,r = 0;
        for(auto n:nums){
            l = max(n,l);
            r += n;
        }
        auto f = [&](int z){
            int g = 0;
            int k = 0;
            for(auto n : nums){
                k+=n;
                if(k > z) {
                    g++;
                    k = n;
                }
            }
            // cout << z <<" "<<g <<"\n";
            return g;
        };
        while(l<=r){
            int mid = (l+r)/2;
            if(f(mid) >= m){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return l;
    }
};
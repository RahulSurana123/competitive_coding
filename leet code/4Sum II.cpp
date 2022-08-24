

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> m;
        for(auto x: nums1){
            for(auto z: nums2){
                m[x+z]++;
            }
        }
        int ans = 0;
        for(auto x: nums3){
            for(auto z: nums4){
                ans += m[-(x+z)];
            }
        }
        return ans;
    }
};
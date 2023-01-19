



/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:

    long long int ans = 0;

    int df(int x){
        if(x <= 1) return x;
        return x+df(x-1);
    }

    int subarraysDivByK(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        vector<int> ps(nums.size()+1,0);
        // cout << ((-104)%k)<<"\n";
        ps[0] = (nums[0]);
        for(int i = 1 ;i < nums.size(); i++){
            ps[i] = (ps[i-1] +nums[i]) ;
        }
        vector<int> f(100000,0);
        for(int i = 0; i < nums.size(); i++){
             
            f[((ps[i]%k)+k)%k]++;
            // cout << i << " "<< ps[i] <<" \n";
        }
        for(int i = 0; i < k; i++){
           if(f[i]>0)
            ans += df(f[i]-1);
            //  cout << f[i]<<"\n";
        }
        return ans+f[0];
    }
};
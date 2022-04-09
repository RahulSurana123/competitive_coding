

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an integer array nums and an integer k, return the k most frequent elements. 
You may return the answer in any order.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> v;
        for(auto n : nums){
            m[n]++;
            if(m[n] == 1) v.push_back(n);
        }
        sort(v.begin(),v.end(),[&](auto a,auto b){ return m[a]>m[b]; });
        return vector<int>(v.begin(),v.begin()+k);
    }
};
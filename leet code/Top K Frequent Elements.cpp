

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
        vector<int> ans;
        map<int, int> f;
        vector<pair<int, int>> fv;
        ans.reserve(k);
        auto i = 0;
        while(i < nums.size()){
            f[nums[i++]]++;
        }
        
        for(auto [x,y]: f){
            fv.push_back({x,y});
        }
        sort(fv.begin(),fv.end(),[&](auto a, auto b){ return a.second > b.second; });
        for(auto x: fv){
            ans.push_back(x.first);
            k--;
            if(k<=0) break;
        }
        return ans;
    }
};
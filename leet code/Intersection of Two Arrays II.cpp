

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_multiset<int> s,s1;
        for(auto x : nums1){
            s.insert(x);
            // cout << s.count(x)<<" "<< x <<"\n";
        }
        for(auto x : nums2){
            if( s.count(x) && s1.count(x) < s.count(x)){
                // cout << x <<" "<<s1.count(x) <<" " <<s.count(x)<<"\n";
                ans.push_back(x);
                s1.insert(x);
            }
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> p;
        unordered_map<int,int> m;
        for(auto x: nums2){
            while(p.size() && p.top() < x){
                m[p.top()] = x;
                p.pop();
            }
            p.push(x);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            if(m.count(nums1[i])) ans[i] = m[nums1[i]];
            else ans[i] = -1;
        }
        return ans;
    }
};

/*


Solution By Rahul Surana


***********************************


Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.


*************************************/



#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(),nums1.end()),b(nums2.begin(),nums2.end());
        vector<vector<int>> ans(2);
        set<int> q;
        for(auto x: nums1) if(!b.count(x)) q.insert(x);
        ans[0].assign(q.begin(),q.end());
        q.clear();
        for(auto x: nums2) if(!a.count(x)) q.insert(x);
        ans[1].assign(q.begin(),q.end());
        return ans;
    }
};
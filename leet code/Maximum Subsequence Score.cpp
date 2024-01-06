

/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. 
You must choose a subsequence of indices from nums1 of length k.

For chosen indices i0, i1, ..., ik - 1, your score is defined as:

The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
Return the maximum possible score.

A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

 


    ***********************************************************
*/


class Solution {
public:

    static constexpr auto fast_io =  [](){  std::ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL); };
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {

        vector<pair<int,int>> x;
        for(int i =0 ; i < nums1.size(); i++) x.push_back({nums1[i],nums2[i]});
        sort(x.begin(),x.end(),[&](auto &a, auto &b){ return b.second < a.second; });
        priority_queue<int,vector<int>, greater<int>> pq;
        long long s = 0;
        for(int i = 0; i < k; i++){
            s += x[i].first;
            pq.push(x[i].first);
        }
        long long ans = (s*x[k-1].second);

        for(int i = k; i < nums1.size(); i++)
        {
            s += x[i].first - pq.top();
            pq.pop();
            pq.push(x[i].first);
            ans=max(ans,s*x[i].second);
        }

        return ans;
    }
};


/* 

    Solution by Rahul Surana
    
    ***********************************************************

You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


    ***********************************************************
*/


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans;
        set<pair<int, int>> v;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;
        pq.push({nums1[0] + nums2[0], {0, 0}});
        v.insert({0, 0});

        while (k-- && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m && !v.count({i + 1, j})) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                v.insert({i + 1, j});
            }

            if (j + 1 < n && !v.count({i, j + 1})) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                v.insert({i, j + 1});
            }
        }

        return ans;
    }
};
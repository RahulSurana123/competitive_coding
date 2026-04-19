

/* 
    Solution by Rahul Surana
    
    ***********************************************************

You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.


    ***********************************************************
*/

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, n = nums1.size(), m = nums2.size(), ans = 0;
        for(int j = 0; j < m; j++){
            while(i < n && nums1[i] > nums2[j]) i++;
            if(i == n) break;
            if(i <= j) ans = max(ans, j-i); 
            // cout << i <<" "<<j<<"\n";
        }
        return ans;
    }
};

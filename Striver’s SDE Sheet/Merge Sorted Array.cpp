

/* 

    Solution by Rahul Surana
    

    ***********************************************************


You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, 
where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

        

    ***********************************************************
*/



#include <bits/stdc++.h>
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n+m-1;
        n--;
        m--;
        while(n>=0 && m >= 0){
            if(nums1[m] > nums2[n]){
                nums1[k--] = nums1[m--];
            }
            else nums1[k--] = nums2[n--];
        }
        while(n>=0){
            nums1[k--] = nums2[n--];
        }
    }
};
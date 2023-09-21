

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 
 


    ***********************************************************
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int mid = ((m+n)/2);
        bool one = (m+n)%2 == 1;
        int s1 = 0,v1 = 0, s2 = 0, v2 = 0;
        while(s1 + s2 <= mid){
            v2= v1;
            if(s1 != m && s2 != n){
                if(nums1[s1] > nums2[s2]){
                    v1 = nums2[s2++];
                }
                else v1 = nums1[s1++];
            }else if(s1 == m){
                v1 = nums2[s2++];
            }
            else {
                v1 = nums1[s1++];
            }
        }
        if(one) return v1;
        return (v1+v2 )/2.0;
    }
};
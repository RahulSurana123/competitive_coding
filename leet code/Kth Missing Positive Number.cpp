

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.


    ***********************************************************
*/


#include <bits/stdc++.h>
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int c = 0;
        for(int i = 0; i < arr.size(); i++){
            if(k < arr[i] - c) return c + k;
            k-=(arr[i] - c-1);
            c = arr[i];
        }
        return c+k;
    }
};
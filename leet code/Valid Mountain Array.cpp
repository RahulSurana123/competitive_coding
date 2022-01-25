

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size()<3) return false;
        int i = 0;
        while(i<arr.size()-1 && arr[i] < arr[i+1]) i++;
        if(i == 0) return false;
        int j = arr.size()-1;
        while(j>0 && arr[j] < arr[j-1]) j--;
        if(j== arr.size()-1) return false;
        return j==i;
    }
};
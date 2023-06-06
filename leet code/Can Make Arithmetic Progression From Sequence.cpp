

/* 
    Solution by Rahul Surana
    
    ***********************************************************


A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.


    ***********************************************************
*/



#include <bits/stdc++.h>

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dif = arr[0] - arr[1];
        for(int i = 2; i < arr.size(); i++){
            if(arr[i-1] - arr[i] != dif) return false; 
        }
        return true;
    }
};
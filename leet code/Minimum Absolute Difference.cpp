

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int m = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); i++){
            if(m > abs(arr[i] - arr[i-1])){
                m = abs(arr[i] - arr[i-1]);
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
            else if(m == abs(arr[i] - arr[i-1])){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};


/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of integers arr, 
return true if the number of occurrences of each value in the array is unique, or false otherwise.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        sort(arr.begin(),arr.end());
        int n = arr.size(), c = 1;
        for(int i = 1; i < n; i++){
            if(arr[i-1] == arr[i]) c++;
            else { m[c]++; if(m[c]>1) return false; c = 1; }
        }
        if(m[c] == 1) return false;
        return true;
        
    }
};
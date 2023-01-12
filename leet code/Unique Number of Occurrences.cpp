

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
    
    unordered_map<int,int> uo;
    
    bool uniqueOccurrences(vector<int>& arr) {
        for(auto x: arr) uo[x]++;
        set<int> a;
        for(auto y: uo){ if(a.count(uo[y.first])) return false; a.insert(y.second); }
        return true;
    } 
};
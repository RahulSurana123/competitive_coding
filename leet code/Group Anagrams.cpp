

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto &z: strs){
            string x = z;
            sort(x.begin(),x.end());
            mp[x].push_back(z);
        }
        vector<vector<string>> ans;
        for(auto &z: mp){
            ans.push_back(z.second);   
        }
        return ans;
    }
};
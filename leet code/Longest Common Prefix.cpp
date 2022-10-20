

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i = 0; i < strs[0].length(); i++){
            char x = strs[0][i];
            for(int j = 0; j < strs.size(); j++){
                if(strs[j].size() <= i || strs[j][i] != x){
                    return ans;
                }
            }
            ans+=x;
        }
        return strs[0];
    }
};
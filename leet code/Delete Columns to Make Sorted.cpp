

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of n strings strs, all of the same length.

The strings can be arranged such that there is one on each line, making a grid. 
For example, strs = ["abc", "bce", "cae"] can be arranged as:

 



    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {
public:
    Solution(){
        cin.tie(NULL),cout.tie(NULL);
    }
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for(int i = 0 ; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] < strs[j-1][i]) { ans++; break; }
            }
        }
        return ans;
    }
};
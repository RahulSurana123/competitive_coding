

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, find the length of the longest substring without repeating characters.


    ***********************************************************
*/


#include <bits/stdc++.h>


class Solution {

public:
    
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char,int> m;
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(m[s[i]] < 1){
                m[s[i]] += 1;
            }
            else{
                while(m[s[i]] > 0) { m[s[j++]]--; }
                m[s[i]]++;
            }
            // cout << s[i] << " "<<m[s[i]] <<" "<<s[j]<<" "<<m[s[j]] <<"\n";
            if(i-j+1>ans)
                ans = i-j+1;
        }
        return ans;
    }

};
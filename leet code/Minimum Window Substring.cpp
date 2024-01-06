

/* 

    Solution by Rahul Surana
    
    ***********************************************************


Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) 
is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.


    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    string minWindow(string s, string t) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        
        int i = 0, j = 0;
        int li=0,lj=0, mi = INT_MAX;
        unordered_map<char,int> tf,sf;
        
        for(auto x:t){
            tf[x]++;
        }
        
        auto is_match = [&](){
            for(auto x: tf){
                if(x.second > sf[x.first]) return false;
            }
            return true;
        };
        
        while(j <= s.length() && i< s.length()){
            bool d = is_match();
            if(!d){
                sf[s[j]]++;
                j++;
            }
            else{
                if(j-i < mi){
                    mi = j-i;
                    li=i;
                    lj=j;
                }
                sf[s[i]]--;
                i++;
            }
            // cout << d <<" "<< li << " "<< lj << " "<<i <<" "<< j <<"\n";
        }
        
        return mi == INT_MAX? "":s.substr(li,mi);
    }
};
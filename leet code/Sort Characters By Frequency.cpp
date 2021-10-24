

/* 
    Solution by Rahul Surana
    
    ***********************************************************


Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



    ***********************************************************
*/


#include <bits/stdc++.h>

class Solution {
public:
    
    string frequencySort(string s) {
        
        map<char,int> m;
        for(auto x: s){
            m[x]++;
        }
        vector<pair<char,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),[=](auto a, auto b){ return a.second > b.second;});
        string ans = "";
        for(auto x: v){
            while(x.second > 0) {ans+=x.first; x.second--;}
        }
        return ans;
    }
};
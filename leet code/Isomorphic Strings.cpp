

/* 
    Solution by Rahul Surana
    
    ***********************************************************


You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. 
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.


    ***********************************************************
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,char> a,b;
        for(int i = 0;i < s.length(); i++){
            if(a.count(s[i]) && a[s[i]] != t[i]) return false;
            a[s[i]] = t[i];
        }
        for(int i = 0;i < t.length(); i++){
            if(b.count(t[i]) && b[t[i]] != s[i]) return false;
            b[t[i]] = s[i];
        }
        return true;
    }
};